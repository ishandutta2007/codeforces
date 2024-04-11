#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> b;
        for(int i = 0;i < n;i++) b[s[i]]++;
        int Max = -1;
        char q = '0';
        for(auto i : b) {
            if (i.second > Max) {
                q = i.first;
                Max = i.second;
            }
        }

        if (q == 'R') {
            q = 'P';
        }else if (q == 'P') {
            q = 'S';
        }else q = 'R';

        for(int i = 0;i < n;i++) cout << q;
        cout << endl;
    }
}