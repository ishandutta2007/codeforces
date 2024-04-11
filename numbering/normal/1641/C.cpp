#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
struct SegTree {
    vector<int> seg;
    int MAX;
    SegTree(int N) {
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
        fill(seg.begin(),seg.end(),INF);
    }
    void cons() {
        for(int i=MAX/2-1;i>=1;i--) {
            seg[i] = min(seg[2*i],seg[2*i+1]);
        }
    }
    void update(int n) {
        n += MAX/2;
        n /= 2;
        while(n) {
            seg[n] = min(seg[2*n],seg[2*n+1]);
            n /= 2;
        }
    }
    void Edit(int n, int a) {
        seg[n+MAX/2] = min(a,seg[n+MAX/2]);
        update(n);
    }
    int sum(int s, int e, int n, int ns, int ne) {
        if(e<=ns||ne<=s) return INF;
        if(s<=ns&&ne<=e) return seg[n];
        int mid = ns + ne >> 1;
        return min(sum(s,e,2*n,ns,mid),sum(s,e,2*n+1,mid,ne));
    }
    int sum(int s, int e) {
        return sum(s,e,1,0,MAX/2);
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    SegTree tree1(N+5);
    set<int> S;
    int i;
    for(i=0;i<N;i++) S.insert(i);
    while(Q--) {
        int t;
        cin >> t;
        if(t==0) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            if(x==0) {
                auto it = S.lower_bound(l);
                while(it != S.end()) {
                    if(*it > r) break;
                    int n = *it;
                    it++;
                    S.erase(n);
                }
            }
            else {
                tree1.Edit(l,r);
            }
        }
        else {
            int a;
            cin >> a;
            a--;
            if(S.find(a)==S.end()) {
                cout << "NO\n";
                continue;
            }
            auto it = S.lower_bound(a);
            int l, r;
            if(it == S.begin()) {
                l = -1;
            }
            else {
                it--;
                l = *it;
                it++;
            }
            it++;
            if(it == S.end()) {
                r = N;
            }
            else r = *it;
            int mi = tree1.sum(l+1,a+1);
            if(mi < r) cout << "YES\n";
            else cout << "N/A\n";
        }
    }
}