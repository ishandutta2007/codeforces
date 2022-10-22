#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;

ll n,m,k,q,d,h;
ll T;

ll M[1100000];
ll MI[101][101];

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e,t;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m >> q;
    c3 = 0;
    for(c1 = 0; c1 < n; c1++){
        for(c2 = 0; c2 < m; c2++){
            MI[c1][c2] = c3;
            M[c3] = 1;
            c3++;
        }
    }

    for(c1 = 0; c1 < q; c1++){
        cin >> t;
        if(t == 1){
            cin >> a;
            a--;
            b = MI[a][0];
            for(c2 = 0; c2 < m-1; c2++){
                MI[a][c2] = MI[a][c2+1];
            }
            MI[a][m-1] = b;
        }
        if(t == 2){
             cin >> a;
            a--;
            b = MI[0][a];
            for(c2 = 0; c2 < n-1; c2++){
                MI[c2][a] = MI[c2+1][a];
            }
            MI[n-1][a] = b;
        }
        if(t == 3){
            cin >> a >> b >> x;
            a--;
            b--;
            M[MI[a][b]] = x;
        }
    }

    c3 = 0;
    for(c1 = 0; c1 < n; c1++){
        for(c2 = 0; c2 < m; c2++){
            cout << M[c3] << " ";
            c3++;
        }cout << "\n";
    }

	return 0;
}