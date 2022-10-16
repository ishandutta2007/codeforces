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
const int N = 30, mod = 1e9 + 7;
typedef bitset<1000> bit;
template<typename T>
inline void read(T &x){
    int ch = getchar(); x = 0; bool f = false;
    for(;ch < '0' || ch > '9';ch = getchar()) f |= ch == '-';
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
template<typename T>
inline bool chmin(T &a, const T &b){if(a > b) return a = b, 1; return 0;}
int n, s, d, lim, ans;
bit a[N], tmp;
unordered_map<bit, int> M;
void dfs(int dep, const bit &o, int val){
    if(dep == lim){if(!M.count(o)) M[o] = val; else chmin(M[o], val); return;}
    dfs(dep+1, o^a[dep], val+1); dfs(dep+1, o, val);
}
void dfs2(int dep, const bit &o, int val){
    if(dep == s){if(M.count(o)) chmin(ans, M[o]+val); return;}
    dfs2(dep+1, o^a[dep], val+1); dfs2(dep+1, o, val);
}
int main(){
    read(n); read(s); read(d);
    for(Rint i = 0, t, x;i < s;++ i){
        read(t); while(t --){read(x); -- x; a[i].set(x);}
    } lim = s - s / 3;
    dfs(0, tmp, 0);
    while(d --){
        tmp.reset(); int t, x; ans = s + 1; read(t);
        while(t --){read(x); -- x; tmp.set(x);}
        dfs2(lim, tmp, 0); printf("%d\n", ans > s ? -1 : ans);
    }
}