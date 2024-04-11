#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

struct algo {
    vector<int> v;
    algo( int n ) {
        for( int i=0; i<n; i++ ) {
            v.push_back( i );
        }
        for( int a, b, i=1; i<=3*n; i++ ) {
            a = (long long)rand()*rand()%n;
            do {
                b = (long long)rand()*rand()%n;
            } while( a==b );
            swap( v[a], v[b] );
        }
        int li=0;
        cout << n << "\n";
        for( int i=0; i<n; i++ ) {
            if( v[i] == i ) li++;
            cout << v[i]+1 << " ";
        }
        //cout << li << ";";
        //cout << fixed << (double)li/n << "   ";
    }
};

struct algo2 {
    vector<int> v;
    algo2( int n ) {
        for( int i=0; i<n; i++ ) {
            v.push_back( i );
        }
        for( int a, b, i=1; i<=7*n+1; i++ ) {
            a = (long long)rand()*rand()%n;
            do {
                b = (long long)rand()*rand()%n;
            } while( a==b );
            swap( v[a], v[b] );
        }
        int li=0;
        for( int i=0; i<n; i++ ) {
            if( v[i] == i ) li++;
        }
        //cout << li << ";";
        //cout << fixed << (double)li/n << "   ";
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    /*for( int i=0; i<30; i++ ) {
        srand( i );
        algo(  1000000 );
        algo2( 1000000 );
        cout << endl;
    }*/

    //algo( 1000 );
    //return 0;

    int n;
    cin >> n;
    int li=0;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        if( i==a ) li++;
    }
    if( n==5 ) cout << "Petr";
    else if( (n-li) < 0.998*n ) cout << "Petr";
    else cout << "Um_nik";

    return 0;
}
/*

*/