#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=4444;
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
int n,p[maxn],sz[maxn],sl;
bool f[maxn];
void solve(){
	n=read();
	FOR(i,1,2*n) p[i]=read();
	sl=0;
	FOR(i,1,2*n){
		int j=i;
		while(j<=2*n && p[j]<=p[i]) j++;
		j--;
		sz[++sl]=j-i+1;
		i=j;
	}
	FOR(j,0,2*n) f[j]=false;
	f[0]=true;
	FOR(i,1,sl) ROF(j,2*n,sz[i]) f[j]|=f[j-sz[i]];
	puts(f[n]?"YES":"NO");
}
int main(){
	int T=read();
	while(T--) solve();
}