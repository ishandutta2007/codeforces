#include<bits/stdc++.h>
#define Rint register int
#define MP make_pair
#define PB push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<typename T>
inline void read(T &x){
    int ch = getchar(); x = 0; bool f = false;
    for(;ch < '0' || ch > '9';ch = getchar()) f |= ch == '-';
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
template<typename T>
inline bool chmax(T &a, const T &b){if(a < b) return a = b, 1; return 0;}
int t; LL n;
int main(){
    read(t);
    while(t --){
        read(n); LL x = (n/2-n/4+1)%mod, y = (n/4+1)%mod;
        printf("%lld\n", x*y%mod);
    }
}