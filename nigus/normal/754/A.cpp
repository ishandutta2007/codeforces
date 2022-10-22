#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
using namespace std::chrono;

/*
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
*/

typedef long long ll;
typedef long double ld;

ll big = 1000000009ll;
ll n,m,k,r;
ll T;


int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> n;

    bool all0 = 1;
    ll s = 0;
    ll nz = -1;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        if(a != 0 && nz == -1){all0 = 0;nz = c1;}
        s += a;
    }
    if(all0 == 1){
        cout << "NO\n";
    }
    else{cout << "YES\n";
        if(s != 0){
            cout << "1\n1 " << n << "\n";
        }
        else{

            if(nz == n-1){
                cout << "2\n" << "1 " << n-1 << "\n" << n << " " << n << "\n";
            }
            else{

                if(nz == 0){

                    cout << "2\n" << "1 1\n" << "2 " << n << "\n";

                }
                else{

                    cout << "2\n" << "1 " << nz+1 << "\n" << nz+2 << " " << n << "\n";

                }

            }


        }

    }

    return 0;
}