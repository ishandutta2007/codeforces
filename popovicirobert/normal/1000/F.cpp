#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 5e5;
const int INF = 1e9;

int arr[MAXN + 1];
int last[MAXN + 1], prv[MAXN + 1];

int aint[4 * MAXN + 1];

void update(int nod, int left, int right, int pos) {
    if(left == right) {
        aint[nod] = left;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * nod, left, mid, pos);
        else
            update(2 * nod + 1, mid + 1, right, pos);
        if(prv[aint[2 * nod]] < prv[aint[2 * nod + 1]]) {
            aint[nod] = aint[2 * nod];
        }
        else {
            aint[nod] = aint[2 * nod + 1];
        }
    }
}

int query(int nod, int left, int right, int l, int r) {
    if(l <= left && right <= r) {
        return aint[nod];
    }
    else {
        int mid = (left + right) / 2;
        int a = -1, b = -1;
        int ans = INF;
        if(l <= mid)
            a = query(2 * nod , left, mid, l, r);
        if(mid < r)
            b = query(2 * nod + 1, mid + 1, right, l, r);
        if(a == -1)
            ans = b;
        else if(b == -1)
            ans = a;
        else if(prv[a] < prv[b])
            ans = a;
        else
            ans = b;
        return ans;
    }
}

vector < pair <int, int> > qry[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, l, r, q;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        prv[i] = last[arr[i]];
        last[arr[i]] = i;
    }
    cin >> q;
    for(i = 1; i <= q; i++) {
        cin >> l >> r;
        qry[r].push_back({l, i});
    }
    for(i = 1; i <= n; i++) {
        if(prv[i] > 0) {
            prv[prv[i]] = INF;
            update(1, 1, n, prv[i]);
        }
        update(1, 1, n, i);
        for(auto it : qry[i]) {
            int aux = query(1, 1, n, it.first, i);
            if(prv[aux] < it.first) {
                sol[it.second] = arr[aux];
            }
        }
    }
    for(i = 1; i <= q; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
   // cout.close();
    return 0;
}