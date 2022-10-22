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

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;

ll c;

vector<ll> A;

vector<ll> SS;
vector<ll> CS;

vector<ll> A2;

ll ett = 0;


bool comp(ll i, ll j){
    return j < i;
}

bool test(ll i){


ll l = 0;
ll r = n;
while(l < r-1){

    ll mid = (r+l)/2;

    if(A[mid] > i){l = mid;}
    else{r = mid;}

}

ll a = r;
if(A[0] < i)a = 0;

ll s1 = SS[a];

ll ct = c;
ct -= s1;

//if(ct <= i)return 0;

ct -= i;

ll b = a;

//if(i == 4){cout << "b: " << b << "  ct: " << ct << "\n";}

while(b < n){
    if(ct == 0)return 0;

    if(A[b] > ct){

        l = b;
        r = n;

        while(l < r-1){
            ll mid = (r+l)/2;
            if(A[mid] > ct){l = mid;}
            else{r = mid;}
        }
        b = r;
    }
    else{

        l = b;
        r = n;

        if(A[b] == ct)return 0;

        while(l < r-1){
            ll mid = (r+l)/2;
            if(CS[mid+1] - CS[b] <= ct){l = mid;}
            else{r = mid;}
        }



        ct -= CS[l+1] - CS[b];

        b = r;

    }
}


if(ct > m)return 1;
return 0;
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> c;
    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin() , A.end() , comp);

    SS.push_back(0);
    CS.push_back(0);

    m = 0;
    ll score = c;
    for(c1 = 0; c1 < n; c1++){

        CS.push_back(CS[c1] + A[c1]);

        if(A[c1] <= score){
            score -= A[c1];
            SS.push_back(SS[c1] + A[c1]);
            //if(A[c1] == 1)c--;
        }
        else{
            if(A[c1] == 1)ett++;
            SS.push_back(SS[c1]);
        }

        if(A[c1] != 1){
            A2.push_back(A[c1]);
        }
    }

   // n = A2.size();
    m = 0;
    ll ans = -1;

    for(c1 = c; c1 >= 1; c1--){
        if(test(c1))ans = c1;
    }

    if(ans == -1){

        cout << "Greed is good\n";

    }
    else{

        cout << ans << "\n";

    }

	return 0;
}