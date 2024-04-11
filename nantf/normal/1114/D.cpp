#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=5050;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],m,b[maxn],f[maxn][maxn];
int solve(int l,int r){
	if(l==1 && r==m) return 0;
	if(f[l][r]) return f[l][r];
	int ans=INT_MAX;
	if(l!=1) ans=min(ans,solve(l-1,r));
	if(r!=m) ans=min(ans,solve(l,r+1));
	if(l!=1 && r!=m && b[l-1]==b[r+1]) ans=min(ans,solve(l-1,r+1));
	return f[l][r]=ans+1;
}
int main(){
	n=read();
	FOR(i,1,n){
		a[i]=read();
		if(a[i]!=a[i-1]) b[++m]=a[i];
	}
	int ans=INT_MAX;
	FOR(i,1,m) ans=min(ans,solve(i,i));
	printf("%d\n",ans);
}