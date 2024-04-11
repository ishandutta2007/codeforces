#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,mod=998244353;
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
int n,k,a[maxn],f[maxn][maxn],s[maxn][maxn],ans; 
int main(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	FOR(x,1,(a[n]-a[1])/(k-1)){
		FOR(i,0,n) FOR(j,0,k) f[i][j]=s[i][j]=0;
		FOR(i,1,n) f[i][1]=1,s[i][1]=i;
		FOR(j,2,k){
			int cur=0;
			FOR(i,1,n){
				while(cur<i && a[i]-a[cur]>=x) cur++;
				if(cur && a[i]-a[cur]<x) cur--;
				f[i][j]=s[cur][j-1];
				s[i][j]=(s[i-1][j]+f[i][j])%mod;
			}
		}
		ans=(ans+s[n][k])%mod;
	}
	printf("%d\n",ans);
}