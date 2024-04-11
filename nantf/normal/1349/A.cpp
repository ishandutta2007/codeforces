#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
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
int n,mn[maxn][2],cnt[maxn];
bool vis[maxn];
ll ans=1;
int main(){
	n=read();
	MEM(mn,0x3f); 
	FOR(i,1,n){
		int x=read();
		FOR(j,2,sqrt(x)) if(x%j==0){
			int c=0;
			while(x%j==0) x/=j,c++;
			if(c<mn[j][0]) mn[j][1]=mn[j][0],mn[j][0]=c;
			else mn[j][1]=min(mn[j][1],c);
			cnt[j]++;
		}
		if(x>1){
			if(1<mn[x][0]) mn[x][1]=mn[x][0],mn[x][0]=1;
			else mn[x][1]=min(mn[x][1],1);
			cnt[x]++;
		}
	}
	FOR(i,2,2e5) if(!vis[i]){
		if(cnt[i]==n) FOR(j,1,mn[i][1]) ans*=i;
		if(cnt[i]==n-1) FOR(j,1,mn[i][0]) ans*=i;
		FOR(j,2,2e5/i) vis[i*j]=true;
	}
	printf("%lld\n",ans);
}