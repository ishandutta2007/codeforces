#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int k;
namespace io {

    #define in(a) a=read()
    #define out(a) write(a)
    #define outn(a) out(a),putchar('\n')

    #define I_int int 
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; } 
        while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; } 
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
P<int,int> ans[2000005];
int cnt,b;
void print(P<int,int> p){
	out(p.F);putchar(' ');
	outn(p.S);
}
signed main(){
	in(k);
	int t=sqrt(k);
	for(int i=1;i<=t;i++){
		b=i*(i+1)*(2*i+1)/6;
		if(b>k)break;
		if(!((k-b)%(i*(i+1)/2))){
			cnt++;
			ans[cnt].F=i;ans[cnt].S=i+(k-b)/(i*(i+1)/2);
		}
	}
	outn(2*cnt-(ans[cnt].F==ans[cnt].S));
	FOR(i,1,cnt)print(ans[i]),swap(ans[i].F,ans[i].S);
	if(ans[cnt].F!=ans[cnt].S)print(ans[cnt]);
	for(int i=cnt-1;i>=1;i--)print(ans[i]);
	RE 0;
}