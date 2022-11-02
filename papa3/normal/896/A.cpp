#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mx 1000000000000000000ll

int dl[1000010];

string a =  "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";

char foo( int n, int k ) {
    if( n==0 ) {
        if( k >= a.size() ) return '.';
        else return a[k];
    }
    if( k < 34 ) return b[k];
    k-=34;
    if( k < dl[n-1] ) return foo( n-1, k );
    k-=dl[n-1];
    if( k<32 ) return b[34+k];
    k-=32;
    if( k < dl[n-1] ) return foo( n-1, k );
    k-=dl[n-1];
    if( k<2 ) return b[34+32+k];
    return '.';
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int q;
    cin >> q;
    dl[0] = 75;
    for( int i=1; i<=100000; i++ ) {
        dl[i] = dl[i-1]*2+68;
        if( dl[i] > mx ) dl[i] = mx;
    }

    while( q-- ) {
        int n, k;
        cin >> n >> k;
        k--;
        cout << foo( n, k );
    }

    return 0;
}