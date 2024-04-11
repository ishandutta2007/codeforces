#include<string.h>
#include<iostream>
using namespace std;
namespace io {

    #define in(a) a=read()
    #define out(a) write(a),putchar(' ')
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
int a[1000010];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,l,r,i,j;
	in(n);in(l);in(r);
	for(i=1;i<=n;i++)in(a[i]);
	for(i=1;i<=n;i++){
		bool f=1;
		for(j=i-1;j>=max(1,i-l);j--)if(a[j]<a[i]){f=0;break;} 
		for(j=i+1;j<=min(n,i+r);j++)if(a[j]<a[i]){f=0;break;}
		if(f){
			out(i);return 0;
		}
	}
	return 0;
}