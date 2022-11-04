#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

int fr[MAXN + 1];

bool ok[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, p;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        fr[v[i]]++;
    }
    int ans = 0;
    int val = 1;
    for(i = 1; i <= n; i++) {
        if(fr[v[i]] > 1) {
            while(val <= n && fr[val] > 0)
                val++;
            if(val <= n) {
                if(val > v[i] && ok[v[i]] == 0)
                    ok[v[i]] = 1;
                else {
                    ans++;
                    fr[val]++;
                    fr[v[i]]--;
                    v[i] = val;
                }
            }
        }
    }
    cout << ans << endl;
    for(i = 1; i <= n; i++)
        cout << v[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}