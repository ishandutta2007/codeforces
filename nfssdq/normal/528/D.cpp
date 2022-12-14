/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

typedef complex < double > base ;

void fft ( vector < base > & a, bool invert ) {
	int n = ( int ) a. size ( ) ;

	for ( int i = 1 , j = 0 ; i < n ; ++ i ) {
		int bit = n >> 1 ;
		for ( ; j >= bit ; bit >>= 1 )
			j -= bit ;
		j += bit ;
		if ( i < j )
			swap ( a [ i ] , a [ j ] ) ;
	}

	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		double ang = 2 * PI / len * ( invert ? - 1 : 1 ) ;
		base wlen ( cos ( ang ) , sin ( ang ) ) ;
		for ( int i = 0 ; i < n ; i += len ) {
			base w ( 1 ) ;
			for ( int j = 0 ; j < len / 2 ; ++ j ) {
				base u = a [ i + j ] ,  v = a [ i + j + len / 2 ] * w ;
				a [ i + j ] = u + v ;
				a [ i + j + len / 2 ] = u - v ;
				w *= wlen ;
			}
		}
	}
	if ( invert )
		for ( int i = 0 ; i < n ; ++ i )
			a [ i ] /= n ;
}

int cnt[200001];

int multiply ( const vector < int > & a, const vector < int > & b) {
	vector < base > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
	size_t n = 1 ;
	while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
	n <<= 1 ;

	int one = 0;
	REP(i, b.size()) one += b[i];

	fa. resize ( n ) ,  fb. resize ( n ) ;

	fft ( fa, false ) ,  fft ( fb, false ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		fa [ i ] *= fb [ i ] ;
	fft ( fa, true ) ;

    int ret=0;

	for ( size_t i = 0 ; i < a.size() ; ++ i )
    {
        int x=(int) ( fa [ i ] . real ( ) + 0.5 );

        if(x == one) cnt[i]++;
    }

    return ret;
}

string S, T, alphabet = "ACGT";
int sum[200011];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int lenS, lenT, K; cin >> lenS >> lenT >> K;
    cin >> S >> T;
    reverse(S.begin(), S.end());


    REP(i, alphabet.size()){
        set0(sum);
        REP(j, S.size()){
            if(alphabet[i] == S[j]){
                int l = max(0, j-K), r = min((int)S.size(), j+K+1);
                sum[l]++; sum[r]--;
            }
        }

        vector < int > vS, vT;

        REP(j, S.size()){
            if(j) sum[j] += sum[j-1];
            if(sum[j]) vS.pb(1);
            else vS.pb(0);
        }

        REP(j, T.size()){
            if(alphabet[i] == T[j]) vT.pb(1);
            else vT.pb(0);
        }

        multiply(vS, vT);
    }

    int res = 0;

    REP(i, S.size()){
        if(cnt[i] == 4) res++;
    }

    cout << res << endl;
}