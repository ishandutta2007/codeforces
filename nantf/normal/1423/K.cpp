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
const int N = 1000003;
template<typename T>
inline void read(T &x){
    int ch = getchar(); x = 0; bool f = false;
    for(;ch < '0' || ch > '9';ch = getchar()) f |= ch == '-';
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
template<typename T>
inline bool chmax(T &a, const T &b){if(a < b) return a = b, 1; return 0;}
int t, n, pre[N];
int main(){
    read(t);
    for(Rint i = 2;i < N;++ i) pre[i] = 1;
    for(Rint i = 2;i < N;++ i) if(pre[i])
        for(Rint j = i<<1;j < N;j += i) pre[j] = 0;
    for(Rint i = 2;i < N;++ i) pre[i] += pre[i-1];
    while(t --){
        read(n); printf("%d\n", pre[n] - pre[(int)(sqrt(n)+1e-6)] + 1);
    }
}