#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
namespace io {

    #define in(a) a=read()
    #define out(a) write(a)
    #define outn(a) out(a),putchar('\n')

    #define I_int int 
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; } 
        while( c >= '0' && c <= '9' ) { x = (x << 3) + (x << 1) + c - '0' ; c = getchar() ; } 
        return x * f ;
    } 
    char F[ 200 ] ;
    inline void write( I_int x ) {
        if( x == 0 ) { putchar( '0' ) ; return ; }
        I_int tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar( '-' ) ;
        int cnt = 0 ;
        while( tmp > 0 ) {
            F[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar( F[ -- cnt ] ) ;
    }
    #undef I_int

}
using namespace io ;
int n,len[2005],rlen[2005];bool f[2005],rf[2005];
int v[2005][2005],rv[2005][2005];
void dfs(int p){
	if(f[p])RE;
	f[p]=1;
	FOR(i,1,len[p])dfs(v[p][i]);
} 
void rdfs(int p){
	if(rf[p])RE;
	rf[p]=1;
	FOR(i,1,rlen[p])rdfs(rv[p][i]);
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	in(n); 
	FOR(i,1,n){
		FOR(j,1,n){
			in(x);
			if(x){
				v[i][++len[i]]=j;
				rv[j][++rlen[j]]=i;
			}
		}
	}
	dfs(1);
	rdfs(1);
	FOR(i,1,n){
		if(!f[i]||!rf[i]){
			puts("NO");RE 0;
		}
	}
	puts("YES");
	RE 0;
}