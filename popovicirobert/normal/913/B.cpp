#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 6

using namespace std;

vector <int> g[1001];
int fr[1001];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
        fr[x]++;
    }
    for(i = 1; i <= n; i++) {
        if(fr[i] > 0) {
            int cnt = 0;
            for(auto it : g[i]) {
                if(fr[it] == 0)
                    cnt++;
            }
             if(cnt < 3) {
                cout << "No";
                return 0;
             }

        }
    }
    cout << "Yes";
    //cin.close();
    //cout.close();
    return 0;
}