#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050,mod=20190601,base=31;
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
int n,hs[maxn],cur=1;
bool vis[mod],ok[2][maxn];
char s[maxn];
int main(){
	n=read();scanf("%s",s+1);
	FOR(i,1,n) hs[i]=s[i]-'a',ok[0][i]=true;
	FOR(i,2,sqrt(2*n)+1){
		int upr=n-1ll*i*(i-1)/2;
		bool flag=false;
		ROF(j,upr,1){
			if(ok[cur^1][j+i]) vis[hs[j+i]]=true,ok[cur^1][j+i]=false;
			if(vis[hs[j]] || vis[hs[j+1]]) flag=true,ok[cur][j]=true;
		}
		FOR(j,1,upr) vis[hs[j+i]]=false;
		if(!flag) return printf("%d\n",i-1),0;
		FOR(j,1,upr) hs[j]=(base*hs[j]+s[j+i-1]-'a')%mod;
		cur^=1;
	}
}