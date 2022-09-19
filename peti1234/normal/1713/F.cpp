#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, t[c], ans[c];
void solve(vector<int> pos, vector<int> ert) {
    /*cout << "solve\n";
    for (auto x:pos) cout << x << " ";
    cout << "\n";
    for (auto x:ert) cout << x << " ";
    cout << "\n";*/

    int si=pos.size();
    assert(pos.size()==ert.size());
    if (si==1) {
        ans[pos[0]]=ert[0];
        return;
    }
    vector<int> pos2, ert2;
    for (int i=0; i+1<si; i+=2) {
        pos2.push_back(pos[i+1]);
        ert2.push_back(ert[i]^ert[i+1]);
    }
    solve(pos2, ert2);

    pos2.clear(), ert2.clear();

    for (int i=1; i<si; i+=2) {
        pos2.push_back(pos[i-1]);
        ert2.push_back(ert[i]);
    }
    if (si%2) {
        int kov=ert.back();
        for (int j=1; j<si; j+=2) {
            if (((si-1) & j)==0) {
                //cout << "valt " << j << " " << pos[j] << " " << ans[pos[j]] << "\n";
                kov^=ans[pos[j]];
            }
        }
        pos2.push_back(pos.back());
        ert2.push_back(kov);
    }
    solve(pos2, ert2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> a, b;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        a.push_back(i), b.push_back(t[i]);
    }
    solve(a, b);
    for (int i=n-1; i>=0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
3
0 2 1
*/