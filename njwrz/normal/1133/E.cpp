#include <bits/stdc++.h>
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
int f[5005][5005],a[5005];
int main(){
	int n,m,t,ans=0,i,j;
	in(n);in(m);
	for(i=1;i<=n;i++)in(a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			t=lower_bound(a+1,a+i+1,a[i]-5)-a;
			t--;
			f[i][j]=max(f[i-1][j],max(f[i][j-1],f[t][j-1]+i-t));
		}
	}
	out(f[n][m]);
	return 0;
}