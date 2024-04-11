#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=5050,mod=998244353;
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
int n,a[maxn],f[maxn][maxn/2][3];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,0,n) FOR(j,0,(n+1)/2) f[i][j][0]=f[i][j][1]=f[i][j][2]=1e9;
	f[0][0][0]=0;
	FOR(i,1,n) FOR(j,0,(i+1)/2){
		f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
		f[i][j][1]=f[i-1][j][2];
		if(j){
			f[i][j][2]=f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1);
			if(i>=2) f[i][j][2]=min(f[i-1][j-1][1]+max(0,min(a[i-1],a[i-2]-1)-a[i]+1)+max(0,a[i+1]-a[i]+1),f[i][j][2]);
		}
	}
	FOR(i,1,(n+1)/2) printf("%d ",min(min(f[n][i][0],f[n][i][1]),f[n][i][2]));
}