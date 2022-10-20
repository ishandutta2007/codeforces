#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 8e5 + 5;
const int INF = 100001;
int seg[maxn], mn[maxn], u, v;
int a[maxn];
vector<int> e[maxn];
void pull(int idx) {
    mn[idx] = min(mn[idx*2], mn[idx*2+1]) + seg[idx];
}
void push(int idx) {
    seg[idx*2] += seg[idx];
    seg[idx*2+1] += seg[idx];
    seg[idx] = 0;
    pull(idx*2);
    pull(idx*2+1);
    pull(idx);
}
void add(int l, int r, int idx, int val) {
    if(u <= l && r <= v) {
        if(l == r){
            seg[idx] += val;
            mn[idx] = seg[idx];
            return;
        }
        seg[idx] += val;
        push(idx);
        return;
    }
    int m = (l+r)/2;
    if(u <= m) add(l, m, idx*2, val);
    if(v > m) add(m+1, r, idx*2+1, val);
    pull(idx);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        memset(seg, 0, sizeof(int)*maxn/2);
        memset(mn, 0, sizeof(int)*maxn/2);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            u = 0;
            v = a[i];
            add(0, INF, 1, 1);
        }
        for(int i = 0; i < m; i++) e[i].clear();
        for(int i = 0; i < m; i++) {
            int num;
            cin >> num;
            for(int j = 0; j < num; j++) {
                int x;
                cin >> x;
                e[i].push_back(x);
            }
        }
        for(int i = 0; i < m; i++) {
            long long s = 0;
            for(auto k: e[i]) s += k;
            s = (s-1)/e[i].size() + 1;
            u = 0, v = s;
            add(0, INF, 1, -1);
        }
        for(int i = 0; i < m; i++) {
            long long s = 0;
            for(auto k: e[i]) s += k;
            for(auto k: e[i]) {
                long long bef = s, aft = s-k;
                bef = (bef-1)/e[i].size() + 1;
                aft = (aft-1)/(e[i].size()-1) + 1;
                u = 0;
                v = bef;
                add(0, INF, 1, 1);
                u = 0;
                v = aft;
                add(0, INF, 1, -1);
                if(mn[1] >= 0) {
                    cout << 1;
                }
                else {
                    cout << 0;
                }
                u = 0;
                v = bef;
                add(0, INF, 1, -1);
                u = 0;
                v = aft;
                add(0, INF, 1, 1);
            }
        }
        cout << endl;
    }
    return 0;
}