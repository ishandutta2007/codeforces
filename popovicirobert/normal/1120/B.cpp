#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MAXN = (int) 1e5;

char a[MAXN + 1], b[MAXN + 1];
vector < pair <int, int> > sol;
int n;

void solve(int pos, int sign) {
    if(sign == 1) {
        if(a[pos + 1] == 9) {
            solve(pos + 1, -1);
        }
        a[pos]++, a[pos + 1]++;
    }
    else {
        if(a[pos + 1] == 0) {
            solve(pos + 1, 1);
        }
        a[pos]--, a[pos + 1]--;
    }
    sol.push_back({pos, sign});
    if(sol.size() == MAXN) {
        for(auto it : sol) {
            cout << it.first << " " << it.second << "\n";
        }
        exit(0);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> a + 1 >> b + 1;
    ll ans = 0, s = 0;
    for(i = 1; i <= n; i++) {
        a[i] -= '0', b[i] -= '0';
        ans += llabs(b[i] - a[i] - s);
        s = b[i] - a[i] - s;
    }
    if(s != 0) {
        cout << -1;
        return 0;
    }
    cout << ans << "\n";
    for(i = 1; i <= n; i++) {
        while(a[i] != b[i]) {
            if(a[i] < b[i]) {
                solve(i, 1);
            }
            else {
                solve(i, -1);
            }
        }
    }
    for(auto it : sol) {
        cout << it.first << " " << it.second << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}