#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,sum=0; 
	in(n);
	FOR(i,1,n){
		int t;
		in(t);
		sum+=t-i;
	} 
	FOR(i,1,sum%n){
		out(sum/n+i+1);putchar(' ');
	}
	FOR(i,sum%n+1,n){
		out(sum/n+i);putchar(' ');
	}
	RE 0;
}