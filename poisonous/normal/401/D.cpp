#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std ;
 
#define maxs ( 1 << 18 )
#define maxd 110
#define maxn 18
 
unsigned long long f[ maxs ][ maxd ] , n , tot , d , cnt[ 10 ] ;
char s[ maxn ] ;
 
int main(  ) {
        scanf( "%s%d" , s , &d ) ;
        for (unsigned long long i = 0 ; i < ( 1 << strlen( s ) ) ; ++ i ) {
            for (unsigned long long j = 0 ; j < d ; ++ j ) {
                f[ i ][ j ] = 0 ;
            }
        }
        memset( cnt , 0 , sizeof( cnt ) ) ;
        for (unsigned long long i = 0 ; i < strlen( s ) ; ++ i ) {
            cnt[ s[ i ] - '0' ] ++ ;
        }
        f[ 0 ][ 0 ] = 1 ;
        for (unsigned long long i = 0 ; i < ( 1 << strlen( s ) ) ; ++ i ) {
            for (unsigned long long j = 0 ; j < d ; ++ j ) if ( f[ i ][ j ] ) {
                for (unsigned long long k = 0 ; k < strlen( s ) ; ++ k ) if ( (i!=0&&! ( ( 1 << k ) & i ) )||(i==0&&! ( ( 1 << k ) & i )&&s[k]!='0')) {
                    unsigned long long st = i | ( 1 << k ) , sd = ( j * 10 + s[ k ] - '0' ) % d ;
                    f[ st ][ sd ] += f[ i ][ j ] ;
                }
            }
        }
        unsigned long long ans = f[ ( 1 << strlen( s ) ) - 1 ][ 0 ] ;
        for (unsigned long long i = 0 ; i < 10 ; ++ i ) {
            for (unsigned long long j = 1 ; j <= cnt[ i ] ; ++ j ) {
                ans /= j ;
            }
        }
        printf( "%I64u\n" , ans ) ;
}