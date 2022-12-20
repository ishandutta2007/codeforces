#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=1e5+5;
int nr,ng,nb;
typedef long long ll;
ll r[maxn],g[maxn],b[maxn];
const ll inf=9e18;
ll sq(ll x){
	return x*x;
}
ll solve(int nr,int ng,int nb,ll* r,ll* g,ll* b){
	ll ans=inf;
	for(int i=0;i<nr;i++){
		int y=lower_bound(g,g+ng,r[i])-g,z=upper_bound(b,b+nb,r[i])-b-1;
		if(y<ng&&z>=0) ans=min(ans,sq(r[i]-g[y])+sq(g[y]-b[z])+sq(b[z]-r[i]));
	}
	return ans;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	nr=readint();
    	ng=readint();
    	nb=readint();
    	for(int i=0;i<nr;i++) r[i]=readint();
    	for(int i=0;i<ng;i++) g[i]=readint();
    	for(int i=0;i<nb;i++) b[i]=readint();
    	sort(r,r+nr);
    	sort(g,g+ng);
    	sort(b,b+nb);
    	ll ans=inf;
    	ans=min(ans,solve(nr,ng,nb,r,g,b));
    	ans=min(ans,solve(nr,nb,ng,r,b,g));
    	ans=min(ans,solve(ng,nr,nb,g,r,b));
    	ans=min(ans,solve(ng,nb,nr,g,b,r));
    	ans=min(ans,solve(nb,nr,ng,b,r,g));
    	ans=min(ans,solve(nb,ng,nr,b,g,r));
    	printf("%lld\n",ans);
	}
    return 0;
}