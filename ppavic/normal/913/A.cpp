#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair < int,int > pii;
typedef pair < ll ,ll > pll;
typedef pair < double, double > pdd;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n,m;

ll pot(ll A){
    ll sol = 1;
    ll bs = 2;
    for(;A;A/=2LL){
        if(A&1LL)
            sol = (sol * bs) % m;
        bs = (bs * bs) % m;
    }
    return sol;
}

int main(){
    cin >> n >> m;
    if(n > 30) cout << m << endl;
    else cout << m % (1LL << n);
}