#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m,a[maxn][maxn],b[maxn][maxn];
bool in[maxn][maxn];
struct wtf{
	int v,x,y;
	bool operator<(const wtf &w)const{return v<w.v;}
}w[maxn*maxn];
void solve(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) a[i][j]=read(),b[i][j]=in[i][j]=0,w[(i-1)*m+j]=(wtf){a[i][j],i,j};
	sort(w+1,w+n*m+1);
	FOR(i,1,m){
		int x=w[i].x,y=w[i].y;
		b[x][i]=a[x][y];
		in[x][y]=true;
	}
	FOR(i,1,n){
		int cur=1;
		FOR(j,1,m) if(!b[i][j]){
			while(in[i][cur]) cur++;
			b[i][j]=a[i][cur];
			cur++;
		}
	}
	FOR(i,1,n){
		FOR(j,1,m) printf("%d ",b[i][j]);
		puts("");
	}
}
int main(){
	int T=read();
	while(T--) solve();
}