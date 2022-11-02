#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;

const int inf = 1e15;
const int max_n = 53;

int n;
int a[max_n], st[max_n];

void build() {
    for(int i = 0;i < n;i++) {
        st[i] = i;
        for(int j = i - 1;j >= 0;j--) {
            if (a[j] + 1 != a[j + 1]) break;
            st[i] = j;
        }
    }
}

pii get() {
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            if (a[i] == a[j] + 1) return mp(i, j);
        }
    }
    return mp(-1ll, -1ll);
}

void req(vector<int> b) {
    vector<int> c(n);

    int id = 0;
    for(int l : b) {
        for(int i = 0;i < l;i++) {
            c[n - id - l + i] = a[id + i];
        }
        id += l;
    }

    for(int i = 0;i < n;i++)
        a[i] = c[i];
}


void solve() {
    cin >> n;

    for(int i = 0;i < n;i++)
        cin >> a[i];


    vector<vector<int>> res;

    while(true) {
        build();
        if (st[n - 1] == 0) break;

        pii ind = get();

        vector<int> temp;
        temp.emplace_back(ind.fi);
        temp.emplace_back(st[ind.se] - ind.fi);
        temp.emplace_back(ind.se - st[ind.se] + 1);
        temp.emplace_back(n - ind.se - 1);

        while(true) {
            bool del = false;
            for(int i = 0;i < sz(temp);i++) {
                if (temp[i] == 0) {
                    temp.erase(i + temp.begin());
                    del = true;
                    break;
                }
            }
            if (!del) break;
        }


        req(temp);

        res.emplace_back(temp);
    }

    cout << res.size() << endl;
    for(auto i : res) {
        cout << i.size() << " ";
        for(int j : i)
            cout << j << " ";
        cout << endl;
    }

}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}