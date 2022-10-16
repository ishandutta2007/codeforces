#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=5050,mod=1000000007;
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
int n,m,s[maxn],f[maxn],h[maxn],l[maxn],r[maxn],ans1,ans2=1,sl[maxn][maxn],sr[maxn][maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) s[i]=read();
	FOR(i,1,m) f[i]=read(),h[i]=read();
	FOR(i,1,m){
		int res=h[i];
		FOR(j,1,n){
			if(s[j]==f[i]) res--;
			if(!res){l[i]=j;break;}
		}
		if(res) l[i]=n+1;
		res=h[i];
		ROF(j,n,1){
			if(s[j]==f[i]) res--;
			if(!res){r[i]=j;break;}
		}
		if(res) r[i]=0;
		sl[l[i]][f[i]]++;
		sr[r[i]][f[i]]++;
	}
	FOR(i,1,n) FOR(j,1,n) sl[i][j]+=sl[i-1][j];
	ROF(i,n,1) FOR(j,1,n) sr[i][j]+=sr[i+1][j];
	FOR(i,1,m) if(r[i]){
		int tot1=1,tot2=1;
		FOR(j,1,n) if(j!=f[i]){
			int c=sr[r[i]+1][j];
			if(!c) continue;
			tot1++;
			tot2=1ll*tot2*c%mod;
		}
		if(tot1>ans1) ans1=tot1,ans2=0;
		if(tot1==ans1) ans2=(ans2+tot2)%mod;
	}
	FOR(i,1,m) if(l[i]!=n+1){
		int tot1=1,tot2=1;
		FOR(j,1,n) if(j!=f[i]){
			int c1=sr[l[i]+1][j],c2=sl[l[i]-1][j];
			if(c1<c2) swap(c1,c2);
			if(!c1) continue;
			if(!c2){
				tot1++;
				tot2=1ll*tot2*c1%mod;
			}
			else if(c1==1){
				tot1++;
				tot2=2ll*tot2*c1%mod;
			}
			else{
				tot1+=2;
				tot2=1ll*tot2*c2%mod*(c1-1)%mod;
			}
		}
		else{
			int c=sr[l[i]+1][j]-(r[i]>l[i]);
			if(!c) continue;
			tot1++;
			tot2=1ll*tot2*c%mod;
		}
		if(tot1>ans1) ans1=tot1,ans2=0;
		if(tot1==ans1) ans2=(ans2+tot2)%mod;
	}
	printf("%d %d\n",ans1,ans2);
}