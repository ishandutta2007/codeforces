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
ll n,m,q,d,h,k,w,x;
ll T;

short DP[501][251][501] = {0};
vector<ll> A;

ll dp(ll i, ll s1, ll s2){

if(s1 == 0 && s2 == k){
    return 1;
}
if(i == n){return 0;}
if(s1 < 0 || s2 > k || s2 < 0){return 0;}
if(DP[i][s1][s2] != -1){return DP[i][s1][s2];}

short ans = (dp(i+1,s1,s2)==1 || dp(i+1,s1-A[i],s2)==1 || dp(i+1,s1,s2+A[i])==1);
DP[i][s1][s2] = ans;
return ans;

}


int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e,g;
    ll x,y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    for(c1 = 0; c1 < 501; c1++){
        for(c2 = 0; c2 < 251; c2++){
            for(c3 = 0; c3 < 501; c3++){
                DP[c1][c2][c3] = -1;
            }
        }
    }


    cin >> n >> k;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    vector<ll> ANS;
    for(c1 = 0; c1 <= k/2; c1++){
        if(dp(0,c1,c1) == 1){
            ANS.push_back(c1);
            if(k-c1 != c1){
            ANS.push_back(k-c1);}
        }
    }

    sort(ANS.begin() , ANS.end());
    cout << ANS.size() << "\n";

    for(c1 = 0; c1 < ANS.size(); c1++){
        cout << ANS[c1] << " ";
    }



	return 0;

}