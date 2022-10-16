#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define MP make_pair
#define PB push_back
#define INP scanf
#define OUT printf

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;
typedef pair < string,int> psi;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

llint n,k,m;

llint fastpot(llint x,llint y){
    llint sol = 1;
    llint base = x;
    while(y > 0LL){
        if(y%2LL == 1LL) sol = sol * base % MOD;
        base = base * base % MOD;
        y /= 2LL;
    }
    return sol;
}

int main() {
    cin >> n >> m >> k;
    if((n+m)%2 == 1 && k == -1){
        cout << 0 << endl;
        return 0;
    }
    cout << fastpot(fastpot(2 , n-1),m-1) << endl;
    return 0;
}