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

vector<ll> K;
vector<ll> A;
vector<ll> ind;

ll score;

bool comp(ll i, ll j){
return A[i] < A[j];
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,g,c;
    ll x,y,z;
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;

     cin >> a >> b;
     score = a;

    for(c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        ind.push_back(c1);
        A.push_back(a);
        K.push_back(b-a+1ll);
    }

    priority_queue<ll> pq;


    ll place = 1ll;
    ll ans = n;
    ll p = n-2;

    sort(ind.begin() , ind.end() , comp);



    while(A[ind[p]] > score){
        pq.push(-K[ind[p]]);
        p--;
        place++;
        if(p == -1)break;
    }
    ans = place;


    while(score > 0){

        if(pq.empty()){

           break;

        }

        score += pq.top();
        if(score < 0) break;
        pq.pop();
        place--;
        if(p >= 0){
            while(A[ind[p]] > score){
                pq.push(-K[ind[p]]);
                p--;
                place++;
                if(p == -1)break;
            }
        }
       // cout << place << "  " << score << "\n";

        ans = min(ans , place);
    }
    cout << ans << "\n";

	return 0;
}