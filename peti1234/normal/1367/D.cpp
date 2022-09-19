#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, x, db[32], ans[c], t[c];
vector<int> v;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> s >> n, x=27;
        for (int i=0; i<31; i++) db[i]=0;
        for (int i=0; i<s.size(); i++) db[s[i]-'a']++;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) {
            v.clear();
            for (int j=1; j<=n; j++) if (!t[j]) v.push_back(j);
            int si=v.size();
            while(db[x]<si) x--;
            for (int j=0; j<si; j++) {
                int p=v[j];
                ans[p]=x, t[p]--;
                for (int k=1; k<=n; k++) t[k]-=abs(k-p);
            }
            x--;
        }
        for (int i=1; i<=n; i++) {
            char q=ans[i]+'a';
            cout << q;
        }
        cout << "\n";
    }
    return 0;
}