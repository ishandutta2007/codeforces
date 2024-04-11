#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N (1<<19)

pair<int,int> p[2*N];

#define INF 999999999

void set(int k, int x) {
    k += N;
    p[k] = {x,k-N};
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = min(p[2*k],p[2*k+1]);
    }
}

pair<int,int> getMin(int a, int b) {
    a += N; b += N;
    pair<int,int> r = p[a];
    while (a <= b) {
        if (a%2 == 1) r = min(r,p[a++]);
        if (b%2 == 0) r = min(r,p[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

int n, q;

int a[505050];
int pos[505050];
int pre[505050];

vector<vector<int>> query;
int result[505050];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({r,l,i});
    }
    sort(query.begin(),query.end());
    int k = 0;
    for (int i = 0; i < q; i++) {
        int l = query[i][1], r = query[i][0], pos = query[i][2];
        while (k < r) {
            k++;
            set(pre[k],INF);
            set(k,pre[k]);
        }
        auto x = getMin(l,r);
        if (x.first < l) {
            result[pos] = a[x.second];
        } else {
            result[pos] = 0;
        }
    }
    for (int i = 1; i <= q; i++) cout << result[i] << "\n";
}