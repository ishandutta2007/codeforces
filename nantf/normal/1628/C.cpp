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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn][maxn],ans;
bool in[maxn][maxn];
void clear(){
	ans=0;
	FOR(i,1,n) FOR(j,1,n) in[i][j]=false;
}
inline void work(int x,int y){
	ans^=a[x][y];
	if(x>1) in[x-1][y]^=1;
	if(x<n) in[x+1][y]^=1;
	if(y>1) in[x][y-1]^=1;
	if(y<n) in[x][y+1]^=1;
}
void solve(){
	n=read();
	FOR(i,1,n) FOR(j,1,n) a[i][j]=0;
	FOR(i,1,n) FOR(j,1,n) a[i][j]=read();
	if(n==2){
		printf("%d\n",a[1][1]^a[1][2]);
	}
	else{
		FOR(_,0,1){
			int x=1,y=1;
			FOR(i,0,4*(n-1)-1){
				if(i%4==0) work(x,y);
				if(x==1){
					if(y==n) x++;
					else y++;
				}
				else if(x==n){
					if(y==1) x--;
					else y--;
				}
				else{
					if(y==n) x++;
					else x--;
				}
			}
			FOR(i,1,n) FOR(j,1,n) if(((i+j)&1) && !in[i][j]) work(i+1,j);
			FOR(i,1,n) reverse(a[i]+1,a[i]+n+1),reverse(in[i]+1,in[i]+n+1);
		}
		printf("%d\n",ans);
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve(); 
}