#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;




signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> pr(2, vector<int>(n + 1)), d(2, vector<int>(n + 1, 0));

    for(int i = n - 1;i >= 0;i--) {
        if (s[i] == '1') d[0][i] = 0;
        else d[0][i] = 1 + d[0][i + 1];
        if (s[i] == '0') d[1][i] = 0;
        else d[1][i] = 1 + d[1][i + 1];
    }

    for(int i = 0;i < n;i++) {
        if (s[i] == '1') pr[0][i] = 0;
        else pr[0][i] = 1 + (i == 0 ? 0 : pr[0][i - 1]);
        if (s[i] == '0') pr[1][i] = 0;
        else pr[1][i] = 1 + (i == 0 ? 0 : pr[1][i - 1]);
    }



    for(int x = 1;x <= n;x++) {
        int v = 0, le = 0;

        int res = 0;

        while(v < n) {
            int num1 = d[0][v] + min(pr[0][v] - 1, v - le);
            int num2 = d[1][v] + min(pr[1][v] - 1, v - le);

            //cout << v << " " << num1 << " " << num2 << endl; 
            if (num1 >= x && (num2 < x || pr[0][v] > pr[1][v])) {
                v += x - min(pr[0][v] - 1, v - le);
                le = v;
                res++;
            }else if (num2 >= x) {
                v += x - min(pr[1][v] - 1, v - le);
                le = v;
                res++;
            }else {
                v += x;
            }
        }


        cout << res << " ";
    }

}