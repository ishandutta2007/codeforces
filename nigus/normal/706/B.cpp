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
vector<ll> ind;
vector<ll> Q;
ll ANS[100000] = {0};

bool comp(ll i, ll j){
return Q[i] < Q[j];}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll y,z;
    //freopen("stress.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a; A.push_back(a);
    }
    cin >> q;
    for(c1 = 0; c1 < q; c1++){
        cin >> a;
        Q.push_back(a);
        ind.push_back(c1);
    }
    sort(A.begin(),A.end());
    sort(ind.begin() , ind.end(),comp);
    ll ans = 0;
    for(c1 = 0; c1 < q; c1++){
        a = ind[c1];
        if(ans < n){
            while(A[ans] <= Q[a]){
                ans++;
                if(ans >= n){break;}
            }
        }
        ANS[a] = ans;

    }


    for(c1 = 0; c1 < q; c1++){
        cout << ANS[c1] << "\n";
    }

	return 0;
}