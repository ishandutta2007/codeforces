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

vector<ll> A;
vector<ll> F;

vector<ll> L;
vector<ll> R;
vector<ll> ind;
vector<ll> ind2;
vector<ll> ord;
ll ones = 9223372036854775807ll;

ll parent(ll i){
    return i-(i&(ll(i^ones)+1ll));
}

ll next(ll i){
    if(i==0){return 1ll;}
    return i+(i&(ll(i^ones)+1ll));
}

void update(ll i, ll to){
    if(i >= n){return;}
    ll j = i+1;
    while(j <= n){
        F[j] += to-A[i];
        j = next(j);
    }
    return;
}

ll prefix(ll i){
if(i == 0){return 0;}
return F[i]+prefix(parent(i));
}


bool comp(ll i, ll j){
    return R[i] < R[j];
}

bool comp2(ll i, ll j){
    return L[i] < L[j];
}

ll bs(){
ll l = 0;
ll r = n+1;
ll look = prefix(n) - k + 1;
while(l < r-1){
    ll mid = (l+r)/2;
    if(prefix(mid) < look){
        l = mid;
    }
    else{
        r = mid;
    }
}
return l;
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,d,e;

    cin >> n >> k;

    for(c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        R.push_back(b);
        L.push_back(a);
        ind.push_back(c1);
        ind2.push_back(c1);
        ord.push_back(0);
    }

    for(c1 = 0; c1 < n+1; c1++){
        A.push_back(0);
        F.push_back(0);
    }

    sort(ind2.begin() , ind2.end() , comp);

    for(c1 = 0; c1 < n; c1++){
        ord[ind2[c1]] = c1;
        //cout << ind2[c1] << " ";
    }

    sort(ind.begin() , ind.end() , comp2);

    ll ans = -1;
    ll a1 = 0;

    for(c1 = 0; c1 < n; c1++){
        a = ind[c1];
        update(ord[a] , 1);
        A[ord[a]] = 1;
        //cout << prefix(n) << "\n";
        if(prefix(n) >= k){

            ll i = bs();

            //cout << i << " " << c1 << "\n";

            ll a2 = max(R[ind2[i]] - L[a] +1, 0ll);

            if(a2 > ans){
                ans = a2;
                a1 = c1;
            }

        }

    }

    cout << ans << "\n";

    bool mark[500000] = {0};

    for(c1 = 0; c1 <= a1; c1++){
        mark[ind[c1]] = 1;
    }
    vector<ll> ANS;

    for(c1 = n-1; c1 >= 0; c1--){
        if(mark[ind2[c1]] == 1){
            ANS.push_back(ind2[c1]);
            cout << ind2[c1]+1 << " ";
        }
        if(ANS.size() == k)break;
    }

    return 0;
}