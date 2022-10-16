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
int n,a[maxn],m,b[maxn],sa,sb,dx[maxn],dy[maxn],xl,yl,wtf[maxn],wl;
bool usea[maxn],useb[maxn];
bitset<maxn*maxn> f[maxn],g[maxn];
void clear(){
	n=m=max(n,m);
	FOR(i,1,n) a[i]=0;
	FOR(i,1,m) b[i]=0;
	FOR(i,0,n) f[i]=0;
	FOR(i,0,m) g[i]=0;
	FOR(i,1,n) usea[i]=false;
	FOR(i,1,m) useb[i]=false;
	FOR(i,1,xl) dx[i]=0;
	FOR(i,1,yl) dy[i]=0;
	FOR(i,1,wl) wtf[i]=0;
	sa=sb=xl=yl=wl=0;
	n=m=0;
}
void solve(){
	n=read();
	FOR(i,1,n) sa+=a[i]=read();
	m=read();
	FOR(i,1,m) sb+=b[i]=read();
	if(n!=m || sa%2!=0 || sb%2!=0) return puts("No"),clear();
	f[0][0]=1;
	FOR(i,1,n) f[i]=f[i-1]|f[i-1]<<a[i];
	g[0][0]=1;
	FOR(i,1,n) g[i]=g[i-1]|g[i-1]<<b[i];
	if(!f[n][sa/2] || !g[n][sb/2]) return puts("No"),clear();
	int curi=n,curj=sa/2,acnt=0,bcnt=0;
	while(curi){
		if(f[curi-1][curj]) curi--;
		else{
			assert(f[curi-1][curj-a[curi]]);
			curj-=a[curi];
			usea[curi]=true;
			acnt++;
			curi--;
		}
	}
	curi=n,curj=sb/2;
	while(curi){
		if(g[curi-1][curj]) curi--;
		else{
			assert(g[curi-1][curj-b[curi]]);
			curj-=b[curi];
			useb[curi]=true;
			bcnt++;
			curi--;
		}
	}
	wl=0;
	FOR(i,1,n) if(usea[i]) wtf[++wl]=a[i];
	sort(wtf+1,wtf+wl+1,greater<int>());
	if(acnt>bcnt) reverse(wtf+1,wtf+wl+1);
	FOR(i,1,wl) dx[++xl]=wtf[i];
	wl=0;
	FOR(i,1,n) if(!usea[i]) wtf[++wl]=a[i];
	sort(wtf+1,wtf+wl+1,greater<int>());
	if(acnt>bcnt) reverse(wtf+1,wtf+wl+1);
	FOR(i,1,wl) dx[++xl]=-wtf[i];
	wl=0;
	FOR(i,1,n) if(useb[i]) wtf[++wl]=b[i];
	sort(wtf+1,wtf+wl+1);
	if(acnt>bcnt) reverse(wtf+1,wtf+wl+1);
	FOR(i,1,wl) dy[++yl]=wtf[i];
	wl=0;
	FOR(i,1,n) if(!useb[i]) wtf[++wl]=b[i];
	sort(wtf+1,wtf+wl+1);
	if(acnt>bcnt) reverse(wtf+1,wtf+wl+1);
	FOR(i,1,wl) dy[++yl]=-wtf[i];
	int xx=0,yy=0;
	puts("Yes");
	if(acnt<=bcnt){
		FOR(i,1,2*n){
			if(i%2!=0) xx+=dx[i/2+1];
			else yy+=dy[i/2];
			printf("%d %d\n",xx,yy);
		}
	}
	else{
		FOR(i,1,2*n){
			if(i%2==0) xx+=dx[i/2];
			else yy+=dy[i/2+1];
			printf("%d %d\n",xx,yy);
		}
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}