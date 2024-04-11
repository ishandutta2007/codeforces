#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    map<int, int> a;
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        a[v]++;
        if (a[v] % 2 == 0) cnt1++;
        if (a[v] % 4 == 0) cnt2++;
    }

    int q;
    cin >> q;
    while(q--) {
        string s;
        int num;
        cin >> s >> num;
        if (s == "+") {
            a[num]++;
            if (a[num] % 2 == 0) cnt1++;
            if (a[num] % 4 == 0) cnt2++;
        }else{
            a[num]--;
            if (a[num] % 2 == 1) cnt1--;
            if (a[num] % 4 == 3) cnt2--;
        }

        if (cnt2 >= 1 && cnt1 >= 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}