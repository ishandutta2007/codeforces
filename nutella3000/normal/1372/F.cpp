#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 7;
int n;
int a[max_n];

pii print(int l, int r) {
    cout << "? " << l << " " << r << endl;
    pii res;
    cin >> res.first >> res.second;
    return res;
}

void rec(int l, int r, vector<pii>& b) {

    if (b.empty()) b.emplace_back(print(l, r));
    pii last = b[b.size() - 1];

    while(true) {
        pii new_last = print(l, l + last.second - 1);

        if (new_last.first == last.first) {
            int id = l + last.second - (new_last.second);
            if (id != l) {
                vector<pii> temp;
                rec(l, id - 1, temp);
            }

            for(int i = id;i < id + last.second;i++) a[i] = last.first;
            b.erase(b.begin() + b.size() - 1);
            if (id + last.second <= r) rec(id + last.second, r, b);
            break;
        }
        b.emplace_back(new_last);
        last = new_last;
    }
}

void solve() {
    cin >> n;
    vector<pii> temp;
    rec(1, n, temp);

    cout << "! ";
    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    cout << endl;
}


signed main() {
    #ifdef local
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}