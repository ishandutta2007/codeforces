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

ll big = 1000000007ll;
ll n,m,k,r;

ll mil;

vector<ll> L;
vector<ll> R;

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c,e;

    cin >> n >> m;
    mil = n;

    for(c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        mil = min(b-a+1 , mil);
        L.push_back(a);
        R.push_back(b);
    }

    for(c1 = 0; c1 < m; c1++){
        R[c1] -= (R[c1]-L[c1]+1 - mil);
    }
    vector<ll> A;

    for(c1 = 0; c1 < n; c1++){
        A.push_back(0);
    }

    sort(L.begin() , L.end());

    ll maset = -1;
    cout << mil << "\n";


    for(c1 = 0; c1 < n; c1++){
        cout << c1%mil << " ";
    }

    return 0;
}