#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int k, d, t;
    cin >> k >> d >> t;
    t*=2;
    int x = k/d;
    while( x*d < k ) x++;
    int pom = x*d+k;

    int pocz=0, kon = numeric_limits<int>::max()/3;
    //kon = 20;
    int sr;

    //cout << pom << " " << t << "\n";
    while( kon-pocz>1 ) {
        sr = (pocz+kon)/2;
        int a = pom*(sr/(x*d));
        sr-=(sr/(x*d))*x*d;
        a += min( sr, k )*2;
        sr -= k;
        if( sr>0 ) a += sr;

        if( a>=t ) kon = (pocz+kon)/2;
        else pocz = (kon+pocz)/2;
    }

    sr = kon;
    int a = pom*((sr-1)/(x*d));
    sr-=((sr-1)/(x*d))*x*d;
    a += min( sr*2-1, k*2 );
    sr -= k;
    if( sr>0 ) a += sr-1;
    if( a>=t ) cout << kon-1 << ".5";
    else cout << kon;

    return 0;
}

//muyhopstrepntesoee