#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,c[maxn][maxn],cnt[maxn],al,ans[maxn*maxn][maxn];
int main(){
	n=read();
	FOR(i,1,n) FOR(j,1,n) c[i][j]=read();
	while(true){
		FOR(i,1,n) sort(c[i]+1,c[i]+n+1);
		al++;
		FOR(i,1,n) FOR(j,1,n-1) if(c[i][j]==c[i][j+1]){ans[al][i]=c[i][j];c[i][j]=0;break;}
		bool flag=false;
		FOR(i,1,n) if(ans[al][i]){
			FOR(j,i+1,n) if(!ans[al][j]) ans[al][j]=ans[al][j-1];
			if(!ans[al][1]) ans[al][1]=ans[al][n];
			FOR(j,2,i-1) if(!ans[al][j]) ans[al][j]=ans[al][j-1];
			flag=true;
			break;
		}
		if(!flag){al--;break;}
		FOR(i,1,n) FOR(j,1,n) if(!c[i][j]){c[i][j]=ans[al][i==1?n:i-1];break;}
	}
	FOR(i,2,n) FOR(j,i,n){
		al++;
		FOR(k,j,n) ans[al][k]=k-j+1;
		FOR(k,1,j-1) ans[al][k]=n-j+1+k;
	}
	printf("%d\n",al);
	FOR(i,1,al) FOR(j,1,n) printf("%d%c",ans[i][j]," \n"[j==n]);
}