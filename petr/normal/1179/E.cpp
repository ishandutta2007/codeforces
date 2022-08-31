#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll SIZE = (ll) 1e18;
int remains = 200000;

    vector<set<pll>> evals;
    ll need;
    vector<ll> resLeft;
    vector<ll> resRight;

    ll realEval(int fid, ll x) {
        --remains;
        assert(remains >= 0);
        printf("? %d %lld\n", (fid + 1), x);
        fflush(stdout);
        ll realY;
        scanf("%lld", &realY);
        return realY;
    }

    bool compareAt(int fid, ll x, ll y) {
        // Tests if f_fid(x) >= y
        set<pll>& known = evals[fid];
        auto next = known.lower_bound(pll(x + 1, -1));
        auto prev = next;
        --prev;         
        assert(prev->first >= 0);
        assert(prev->first <= x);
        assert(next->first > x);
        assert(next->first <= SIZE + 1);
        if (prev->second >= y) return true;
        if (prev->second + x - prev->first < y) return false;
        if (next->second < y) return false;
        if (next->second + x - next->first >= y) return true;
        ll realY = realEval(fid, x);
        known.insert(pll(x, realY));
        return realY >= y;
    }

    void rec(vector<int>& ids, ll left, ll right, ll base) {
        if (ids.size() == 1) {
            resLeft[ids[0]] = left;
            resRight[ids[0]] = right;
            return;
        }
        int n = ids.size();
        int n1 = n / 2;
        ll interesting = base + n1 * need;
        ll searchLeft = 0;
        ll searchRight = SIZE;
        while (searchRight - searchLeft > 1) {
            //random_shuffle(ids.begin(), ids.end());
            ll searchMiddle = (searchLeft + searchRight) / 2;
            int count = 0;
            int togo = n;
            //double needFrac = n1 / (double) n;
            for (int x : ids) {
                if (compareAt(x, searchMiddle, interesting)) {
                    ++count;
                }
                if (count >= n1) break;
                --togo;
                if (count + togo < n1) break;
                /*double frac = count / (double) (n - togo);
                double stdev = sqrt(needFrac * (1 - needFrac) / (n - togo));
                if (frac - 5 * stdev > needFrac) {
                  count = n1;
                  break;
                }
                if (frac + 5 * stdev < needFrac) {
                  break;
                }*/
            }
            if (count >= n1) {
                searchRight = searchMiddle;
            } else {
                searchLeft = searchMiddle;
            }
        }
        vector<int> ids1(n1);
        vector<int> ids2(n - n1);
        int p1 = 0;
        int p2 = 0;
        for (int x : ids) {
            if (compareAt(x, searchLeft, interesting)) {
                ids1[p1++] = x;
            } else if (!compareAt(x, searchRight, interesting)) {
                ids2[p2++] = x;
            }
        }
        for (int x : ids) {
            if (compareAt(x, searchLeft, interesting)) {
            } else if (!compareAt(x, searchRight, interesting)) {
            } else if (p1 == ids1.size()) {
                ids2[p2++] = x;
            } else {
                ids1[p1++] = x;
            }
        }
        rec(ids1, left, searchRight, base);
        rec(ids2, searchRight, right, interesting);
    }

    int main() {
        int n; scanf("%d", &n);
        scanf("%lld", &need);
        need /= n;
        for (int i = 0; i < n; ++i) {
            set<pll> pts;
            pts.insert(pll(0, 0));
            pts.insert(pll(SIZE, need * n));
            pts.insert(pll(SIZE + 1, need * n));
            evals.push_back(pts);
        }
        vector<int> ids;
        for (int i = 0; i < n; ++i) ids.push_back(i);
        resLeft.resize(n);
        resRight.resize(n);
        rec(ids, 0, SIZE, 0);
        for (int i = 0; i < n; ++i) {
            assert(realEval(i, resRight[i]) - realEval(i, resLeft[i]) >= need);
        } 
        printf("!\n");
        for (int i = 0; i < n; ++i) {
            printf("%lld %lld\n", resLeft[i], resRight[i]);
        }
        fflush(stdout);
    }