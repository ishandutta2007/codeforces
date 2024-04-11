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

bool check(vector<int> a) {
    int sum = 0;
    for(int i : a) {
        sum += i;
        if (sum == 0) return false;
    }
    return true;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;


    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];

        sort(all(a));


        if (!check(a)) {
            sort(all(a), [](int v1, int v2) {return v1 > v2;});
        }

        if (check(a)) {
            cout << "YES" << endl;
            for(int i : a)
                cout << i << " ";
            cout << endl;
        }else cout << "NO" << endl;

    }
}