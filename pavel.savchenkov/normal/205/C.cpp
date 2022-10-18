#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <limits.h>
#include <signal.h>
#include <time.h>
#include <map>
#include <set>
#include <float.h>
 
#define TR(c, i) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++ ) 
#define FOR(i, a, b) for ( i = a; i <= b; i++ )
#define ROF(i, a, b) for ( i = a; i >= b; i-- )
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort( ALL(v) )
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define SWAP(a, b) {typeof(a) T; T=a; a=b; b=T;}
#define SET(x,a) memset(x,a,sizeof(x))
#define IN(x,a) x.find(a) != x.end()  
 
#define SYNC ios_base::sync_with_stdio(false);
 
//#define LIM
#ifdef LIM
        int S, D, Y, O;
        char *inp, *out, *ipos, *opos, DIG[30];
        #define FRMI inp=( char * )malloc( LIM*sizeof( char ) );fread_unlocked( inp,1,LIM,stdin );ipos=inp;
        #define FWM out=( char * )malloc( LIM*sizeof( char ) );opos=out;
        #define FWO fwrite_unlocked( out,opos-out,1,stdout );
        #define GETI(n) n=0;while(*ipos<33){ipos++;}if(*ipos=='-'){S=-1;ipos++;}else{S=1;}while(*ipos>='0'){n=10*n+(*ipos-'0');ipos++;}n*=S;
        #define PUTI(n) O=n;D=0;if(O<0){*opos++='-';O*=-1;}if(!O)*opos++='0';else{while(O){Y=O/10;DIG[D++]=O-Y*10+'0';O=Y;}\
        while(D--)*opos++=DIG[D];}
        #define PUTC(c) *opos++=c;
#endif
 
 
using namespace std;
 
long long mypow(long long a, int n)
{
 long long res = 1LL;
 while (n)
 {
  if  (n & 1) res *= a;
  n >>= 1; a *= a;
 }
 return res;
}

long long int val( int n )
{
        long long int v = 9;
 
        int i;
 
        FOR( i,0,n-2 ) {
                v += 9LL*mypow( 10,i );
        }
 
        return v;
 
}
 
long long int calc( long long int n )
{
        stringstream ss;
        ss << n;
        string t = ss.str();
        ss.str("");
 
        int dig = t.length();
        
        if( dig == 1 ) {
                return n;
        }
 
        int i;
        string s = "";
 
        FOR( i,1,dig-2 ) {
                s += t[i];
        }
        
        long long int fd = t[0] -'0';
        long long int ld = n%10;
                
        long long int a = dig >= 3 ? val(dig-1) : 9LL;
        long long int b = (fd-1) * mypow( 10,dig-2 );
        long long int c = atoll( s.c_str() ) + (int)(ld>=fd);
        
        return a+b+c;
}
 
int main()
{
        long long int a, b;
 
        cin >> a >> b;
 
        cout << calc(b)-calc(a-1) << endl;
 
        return 0;
}