#include <bits/stdc++.h>
 
using namespace std;
vector<int> v[27];
int t[27];
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
        int a=s[i]-'a';
        v[a].push_back(i);
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        for (int i=0; i<27; i++) {
            t[i]=-1;
        }
        string s;
        cin >> s;
        for (int i=0; i<s.size(); i++) {
            int a=s[i]-'a';
            t[a]++;
        }
        int maxi=0;
        for (int i=0; i<27; i++) {
            if (t[i]!=-1) {
                maxi=max(maxi, v[i][t[i]]);
            }
        }
        cout << maxi+1 << "\n";
    }
    return 0;
}