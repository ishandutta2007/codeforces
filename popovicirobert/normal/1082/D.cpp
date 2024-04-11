#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 500;

int deg[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int tot = 0;
    for(i = 1; i <= n; i++) {
        cin >> deg[i];
        tot += deg[i];
    }
    if(tot < 2 * (n - 1)) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << " ";
    vector <int> nodes1, nodes2;
    int cnt1 = 0, cnt2 = 0;
    for(i = 1; i <= n; i++) {
        if(deg[i] >= 2) {
            nodes2.push_back(i);
            cnt2++;
        }
        else {
            nodes1.push_back(i);
            cnt1++;
        }
    }
    int ans = cnt2 - 1;
    if(cnt1 == 1) {
        ans++;
    }
    else if(cnt1 > 1) {
        ans += 2;
    }
    cout << ans << "\n";
    cout << n - 1 << "\n";
    for(i = 0; i + 1 < nodes2.size(); i++) {
        cout << nodes2[i] << " " << nodes2[i + 1] << "\n";
        deg[nodes2[i]]--;
        deg[nodes2[i + 1]]--;
    }
    for(auto it : nodes1) {
        for(auto itr : nodes2) {
            if(deg[itr] > 0) {
                deg[itr]--;
                cout << it << " " << itr << "\n";
                break;
            }
        }
        reverse(nodes2.begin(), nodes2.end());
    }
    //cin.close();
    //cout.close();
    return 0;
}