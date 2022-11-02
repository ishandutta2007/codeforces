#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int max_n = 2e3 + 3;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);


    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int res1 = 0;
    int res2 = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++) {
        res1 += (s1[i] == '+' ? 1 : -1);
        if (s2[i] != '?') 
            res2 += (s2[i] == '+' ? 1 : -1);
        else 
            cnt++;
    }

    int r1 = 1, r2 = 1;
    for(int i = 1;i <= cnt;i++) {
        r2 *= 2;
        r1 *= i;
    }

    int num = (cnt + abs(res1 - res2)) / 2;
    for(int i = 1;i <= num;i++) 
      r1 /= i;
    
    for(int i = 1;i <= cnt - num;i++)
        r1 /= i;

    if (num > cnt)
        r1 = 0;
    cout << (double) r1 / r2;
}