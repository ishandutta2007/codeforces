#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,dis[maxn][8],dis2[8][8],d[maxn],q[maxn*2],h,r,msk[maxn],ans1,cnt[8][256],mn[8][256][8][256];
ll ans2;
char s[maxn];
inline void update(int x,int y){
	if(!y) return;
	if(x>ans1) ans1=x,ans2=0;
	if(x==ans1) ans2+=y;
}
int main(){
	n=read();
	scanf("%s",s+1);
	FOR(i,0,7){
		FOR(j,1,n+8) d[j]=1e9;
		d[q[h=r=n+1]=n+1+i]=0;
		while(h<=r){
			int now=q[h++];
			if(now>n){
				FOR(j,1,n) if(s[j]-'a'==now-n-1 && d[j]>d[now]) d[q[--h]=j]=d[now];
			}
			else{
				if(now!=1){
					if(d[now-1]>d[now]+1) d[q[++r]=now-1]=d[now]+1;
				}
				if(now!=n){
					if(d[now+1]>d[now]+1) d[q[++r]=now+1]=d[now]+1;
				}
				if(d[n+1+s[now]-'a']>d[now]+1) d[q[++r]=n+1+s[now]-'a']=d[now]+1;
			}
		}
		FOR(j,1,n) dis[j][i]=d[j];
		FOR(j,0,7) dis2[i][j]=1e9;
		FOR(j,1,n) dis2[i][s[j]-'a']=min(dis2[i][s[j]-'a'],d[j]);
		FOR(j,1,n) msk[j]|=(dis[j][i]-dis2[i][s[j]-'a'])<<i;
	}
	FOR(i,17,n) cnt[s[i]-'a'][msk[i]]++;
	FOR(i,0,7) FOR(j,0,255) FOR(k,0,7) FOR(l,0,255){
		mn[i][j][k][l]=1e9;
		FOR(x,0,7) mn[i][j][k][l]=min(mn[i][j][k][l],dis2[i][x]+((j>>x)&1)+dis2[k][x]+((l>>x)&1)+1);
	}
	FOR(i,1,n){
		FOR(j,max(i-15,1),min(i+15,n)){
			int mn=abs(i-j);
			FOR(k,0,7) mn=min(mn,dis[i][k]+dis[j][k]+1);
			update(mn,1);
		}
		FOR(j,0,7) FOR(k,0,255) update(mn[s[i]-'a'][msk[i]][j][k],cnt[j][k]);
		if(i+16<=n) cnt[s[i+16]-'a'][msk[i+16]]--;
		if(i-15>=1) cnt[s[i-15]-'a'][msk[i-15]]++;
	}
	cout<<ans1<<" "<<ans2/2<<endl;
}