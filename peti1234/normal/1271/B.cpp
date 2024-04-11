#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> ans;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i=0; i<n-1; i++) {
        if (s[i]!='B') {
            ans.push_back(i+1);
            s[i]='B';
            if (s[i+1]=='B') {
                s[i+1]='W';
            } else {
                s[i+1]='B';
            }
        }
    }
    if (s[n-1]!='B') {
        if (n%2) {
            for (int i=1; i<n; i+=2) {
                ans.push_back(i);
            }
        } else {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << ans.size() << "\n";
    for (int x:ans) {
        cout << x << " ";
    }
    return 0;
}