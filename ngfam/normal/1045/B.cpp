#include <bits/stdc++.h>

using namespace std;

int p[1000005], a[200005];

bool check(int l, int r) {
    if (l > r) return true;
    int m = (l+r) >> 1;
    return m + p[m] >= r;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    bool has_zero = false;
    int last = 0;
    vector<pair<int,int>> ds;
    vector<int> val;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        has_zero = has_zero or (a[i] == 0);
        if (a[i] > last) {
            ds.push_back(make_pair(0,0));
            val.push_back(0);
            ds.push_back(make_pair(last,a[i]-1));
            val.push_back(a[i]-last);
        }
        ds.push_back(make_pair(0,0));
        val.push_back(0);    
        ds.push_back(make_pair(a[i],a[i]));
        val.push_back(-1);
        last = a[i]+1;
    }
    if (last <= m-1) {
        ds.push_back(make_pair(0,0));
        val.push_back(0);    
        ds.push_back(make_pair(last,m-1));
        val.push_back(m-last);
    }
    ds.push_back(make_pair(0,0));
    val.push_back(0);
    int le = 0, ri = -1;
    for (int i = 0; i < val.size(); i++) {
//        cout << i << ' ' << le << ' ' << ri << '\n';
        if (i > ri) {
            le = ri = i;
            while (le >= 0 && ri < val.size() && val[le] == val[ri]) {
                le--; ri++;
            }
            p[i] = ri-i-1;
            le++; ri--;
        }
        else {
            int j = le + (ri-i);
            if (i + p[j] < ri) p[i] = p[j];
            else {
                le = i - (ri-i);
                while (le >= 0 && ri < val.size() && val[le] == val[ri]) {
                    le--; ri++;
                }
                p[i] = ri-1-i;
                le++; ri--;
            }
        }
    }
/*
    for (int i = 0; i < val.size(); i++) {
        cout << "(" << ds[i].first << "," << ds[i].second << ") " << val[i] << ' ' << p[i] << endl;
    }
*/
    vector<int> res;
    int sz = val.size();
    for (int i = 0; i < sz; i++) {
        if (val[i] == 0) continue;
        if (val[i] < 0 || val[i] == 1) {
            if (check(1,i) && check(i+1,sz-1)) res.push_back(ds[i].first);
        }
        else {
            if (val[1] < 0) continue;
            if (!check(2,i-1)) continue;
            if (val[1] > val[i]) continue;
            int p1 = 0, p2 = 0;
            if (i == 1) {
                if (val[sz-2] < 0) {
                    if (check(i+1,sz-1)) res.push_back(ds[i].second);
                }
                else {
                    if (check(i+1,sz-3) && val[sz-2] < val[i]) {
                        res.push_back(ds[i].second-val[sz-2]);
                    }
                }
            }
            else {
                int j = ds[i].first + val[1] - 1;
                if (i == sz-2) {
                    res.push_back(j);
                    continue;
                }
                if (j == ds[i].second) {
                    if (check(i+1,sz-1)) res.push_back(j);
                }
                else {
                    if (check(i+1,sz-3) && val[sz-2] > 0 && j+val[sz-2] == ds[i].second)
                        res.push_back(j);
                }
            }
        }
    }
    printf("%d\n", res.size());
    for (int a : res) printf("%d ", a);
}