#include <bits/stdc++.h>

using namespace std;
int n, k, l, db, ans=1;
bool rossz;
string s;
vector<int> sol[3000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='L') db+=l;
        else l++;
    }
    if (k>db) rossz=true;
    while (db) {
        for (int i=1; i<n; i++) {
            if (s[i]=='L' && s[i-1]=='R') {
                sol[ans].push_back(i), db--, swap(s[i], s[i-1]), i++;
                if (db==k-ans) ans++;
            }
        }
        if (sol[ans].size()) ans++;
    }
    if (ans!=k+1) rossz=true;
    if (rossz) cout << -1 << "\n";
    else for (int i=1; i<=k; i++) {
        cout << sol[i].size() << " ";
        for (int j=0; j<sol[i].size(); j++) cout << sol[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
// Egy kisebb hibm volt, egybknt nem volt nehz.