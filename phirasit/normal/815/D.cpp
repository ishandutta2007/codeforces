#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

const int N = 5e5 + 10;

typedef pair<int, int> pii;

long long tree[N];
set<pii> point, rev_point;

int mxb[N], mxc[N];
int a[N], b[N], c[N];
int n, p, q, r;

multiset<int> y, z;
int idx[N];

void update(int idx, long long val) {
    while (idx <= q) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}
long long query(int idx) {
    long long ans = 0;
    while (idx > 0) {
        ans += tree[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void alter(set<pii>::iterator it, long long mul) {
    update(it->first, mul * (it->first - (it == point.begin() ? 0 : prev(it)->first)) * it->second);
}
pii invert(pii data) {
    return {data.second, data.first};
}
void insert(int y, int z) {

    auto it = point.lower_bound({y, z});
    if (it == point.end() or z > it->second) {
        if (it != point.end()) alter(it, -1);
        it = point.insert({y, z}).first;
        rev_point.insert({z, y});
        while (it != point.begin() and prev(it)->second <= z) {
            alter(prev(it), -1);
            rev_point.erase(invert(*prev(it)));
            point.erase(prev(it));
        }
        alter(it, 1);
        if (next(it) != point.end()) {
            alter(next(it), 1);
        }
    }
}
int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> q >> r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        idx[i] = i;
    }

    sort(idx, idx+n, [&](int id1, int id2) {
        return a[id1] < a[id2];
    });

    for (int i = n; i >= 0; --i) {
        mxb[i] = (i < n ? max(mxb[i+1], b[idx[i]]) : 0);
        mxc[i] = (i < n ? max(mxc[i+1], c[idx[i]]) : 0);
    }

    long long ans = 0ll;
    for (int i = 0; i <= n; ++i) {
        const int id = idx[i];

        long long len = (i >= n ? p : a[idx[i]]) - (i > 0 ? a[idx[i-1]] : 0);

        if (len > 0) {
                
            const int mxy = mxb[i] + 1;
            const int mxz = mxc[i] + 1;

            auto it1 = point.lower_bound({mxy, mxz});
            auto it2 = rev_point.lower_bound({mxz, mxy});

            long long val = (long long) (q - mxy + 1) * (r - mxz + 1);
            if (it1 != point.end() and it2 != rev_point.end()) {
                
                pii left = *it1;
                pii right = invert(*it2);
                
                if (left.first <= right.first) {
                    val -= query(right.first) - query(left.first);
                    val += (long long) (right.first - left.first) * (mxz - 1);
                    val -= (long long) (left.first - mxy + 1) * (left.second - mxz + 1); 
                }
            }
            
            ans += len * val;
        }

        if (i < n) {
            insert(b[id], c[id]);
        }   

    }

    cout << ans << endl;

    return 0;
}