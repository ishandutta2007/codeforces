#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[27];
vector<int> q;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while(w--) {
        cin >> n >> m >> s;
        q.clear();
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            q.push_back(x);
        }
        sort(q.begin(), q.end());
        int r=0;
        q.push_back(n);
        for (int i=0; i<n; i++) {
            while(q[r]==i) r++;
            t[s[i]-'a']+=m+1-r;
        }
        for (int i=0; i<26; i++) cout << t[i] << " ", t[i]=0;
    }
    return 0;
}