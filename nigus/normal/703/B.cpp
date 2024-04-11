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
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;

vector<ll> A;
vector<ll> K;
ll cap[100001] = {0};

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;

    ll su = 0;
    ll suk = 0;

    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        su += a;
    }

    for(c1 = 0; c1 < k; c1++){
        cin >> a;
        a--;
        K.push_back(a);
        cap[a] = 1;
        suk += A[a];
    }

    ll ans = 0;

    for(c1 = 0; c1 < n; c1++){
        if(cap[c1] == 0 && cap[(c1+1)%n] == 0){
            ans += A[c1]*A[(c1+1)%n];
        }
    }

    for(c1 = 0; c1 < k; c1++){
        ans += (su-A[K[c1]])*A[K[c1]];
    }
    ll ans2 = 0;
    for(c1 = 0; c1 < k; c1++){
        ans2 += (suk-A[K[c1]])*A[K[c1]];
    }
    ans -= ans2/2;

    cout << ans << "\n";

	return 0;
}