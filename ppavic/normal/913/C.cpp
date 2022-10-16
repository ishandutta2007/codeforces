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


ll n,l,c[N],reg[N];

int main(){
    cin >> n >> l;
    for(int i = 0;i<n;i++){
        cin >> c[i];
        if(i  >0) c[i] = min(c[i],2 * c[i - 1]);
    }
    for(int i = n;i<33;i++){
        c[i] = 2 * c[i - 1];
    }
    ll sol = 0;
    for(int i = 0;i<33;i++){
        if(l&(1LL<<i)) sol += c[i];
        reg[i] = sol;
    }
    for(int i = 0;i<33;i++){
        if((1LL << i) >= l)
            sol = min(sol, c[i]);
    }
    for(int i = 0;i<32;i++){
        if(i){
            if(l&(1LL<<i))
                reg[i] = min(reg[i], reg[i - 1] + c[i]);
            else
                reg[i] = min(reg[i], reg[i - 1]);
        }
        reg[i] = min(c[i + 1], reg[i]);
    }
    cout << min(reg[31],sol) << endl;
}