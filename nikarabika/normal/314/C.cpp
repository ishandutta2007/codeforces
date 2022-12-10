#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
const LL D = 1000000007;
LL seg[maxn * 4], dp[maxn], xxx[maxn], a[maxn];
int last[maxn];
int n;
vector<pie> all;
vector<int> v;
int address[maxn];

void getlast(){
    for(int i = 1; i <= n; i++)
        v.PB(a[i]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 1; i <= n; i++){
        int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        last[i] = address[id];
        address[id] = i;
    }
}

LL get(int l, int r, int L = 1, int R = n + 1, int id = 1){
    if(l == L and r == R)
        return seg[id];
    int mid = (L + R) >> 1;
    LL ret = 0;
    if(l < mid)
        ret += get(l, min(mid, r), L, mid, id * 2 + 0);
    if(r > mid)
        ret += get(max(l, mid), r, mid, R, id * 2 + 1);
    return ret % D;
}

void change(int idx, int L = 1, int R = n + 1, int id = 1){
    if(R - L == 1){
        seg[id] = dp[idx];
        return;
    }
    int mid = (L + R) >> 1;
    if(idx < mid)
        change(idx, L, mid, id * 2 + 0);
    else
        change(idx, mid, R, id * 2 + 1);
    seg[id] = seg[id * 2 + 0] + seg[id * 2 + 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], all.PB(MP(a[i], i));
    getlast();
    sort(all.begin(), all.end());
    for(int i = 0; i < all.size(); i++){
        int id = all[i].R;
        dp[id] = (((get(1, id + 1) + 1LL) % D) * a[id]) - xxx[last[id]];
        dp[id] = ((dp[id] % D) + D) % D;
        xxx[id] = xxx[last[id]] + dp[id];
        xxx[id] %= D;
        xxx[last[id]] = 0;
        change(id);
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + xxx[i]) % D;
    cout << ans << endl;
    return 0;
}