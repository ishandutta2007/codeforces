/*

DP





ll int
 dp 










*/
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
int n,mod=1e9+7;
int a[500005];
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
int cnt[65];
void solve(){
	in(n);
	FOR(i,1,n)in(a[i]);
	FILL(cnt,0);
	FOR(i,1,n){
		rep(j,0,60){
			if(a[i]&(1ll<<j))cnt[j]++;
		}
	}
	int ans=0;
	FOR(i,1,n){
		int t1=0,t2=0;
		rep(j,0,60){
			if(a[i]&(1ll<<j)){
				t1+=n*((1ll<<j)%mod)%mod;
				t1%=mod;
			}else{
				t1+=cnt[j]*((1ll<<j)%mod)%mod;
				t1%=mod;
			}
		}
		rep(j,0,60){
			if(a[i]&(1ll<<j)){
				t2+=cnt[j]*((1ll<<j)%mod)%mod;
				t2%=mod;
			}
		}
		ans=(ans+t1*t2)%mod;
	}
	outn(ans);
}
signed main(){
	int t;
	in(t);
	while(t--)solve();
	RE 0;
}