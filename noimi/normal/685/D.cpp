#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

#define NotANumber -1791791791

struct query {
    int row, l, r; bool a;
    int lbl, ubr;
    query(int _row, int _l, int _r, bool _a) {row = _row; l = _l; r = _r; a = _a;}
    bool operator<(const query& other) const {
        return row < other.row;
    }
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, int> > points(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i].first, &points[i].second);

    sort(points.begin(), points.end());
    vector<int> xcoords;
    for (int i = 0; i < n; i++) {
        int st;
        if (xcoords.empty())
            st = points[i].first - k + 1;
        else
            st = max(xcoords.back() + 1, points[i].first - k + 1);
        for (int j = st; j <= points[i].first; j++)
            xcoords.push_back(j);
    }

    vector<query> qs;
    for (int i = 0; i < n; i++) {
        qs.push_back(query(points[i].second - k + 1, points[i].first - k + 1, points[i].first, 1));
        qs.push_back(query(points[i].second + 1, points[i].first - k + 1, points[i].first, 0));
    }

    for (query & q : qs) {
        q.lbl = lower_bound(xcoords.begin(), xcoords.end(), q.l) - xcoords.begin();
        q.ubr = upper_bound(xcoords.begin(), xcoords.end(), q.r) - xcoords.begin();
    }
    
    int xcdssz = xcoords.size();
    xcoords.clear();
    xcoords.shrink_to_fit();

    sort(qs.begin(), qs.end());

    vector<int> vec(xcdssz, 0);
    vector<int> lastchanged(xcdssz, NotANumber);
    vector<ll> ans(n);

    for (query q : qs) {
        int lbl = q.lbl;
        int ubr = q.ubr;
        for (int i = lbl; i < ubr; i++) {
            if (lastchanged[i] != NotANumber && vec[i] != 0) {
                ans[vec[i] - 1] += q.row - lastchanged[i];
            }
            if (q.a)
                vec[i]++;
            else
                vec[i]--;
            lastchanged[i] = q.row;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}