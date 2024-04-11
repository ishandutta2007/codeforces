#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, k, maxi, ans, s, t[c], pos[c];
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, maxi=0, ans=0, sz.clear();
        for (int i=0; i<n; i++) cin >> s, sz.push_back(s), pos[i]=0;
        for (int i=0; i<n; i++) cin >> s;
        sort(sz.begin(), sz.end()), s=0;
        for (int i=0; i<n; i++) {
            while(s<n && sz[s]-sz[i]<=k) s++;
            t[i]=s;
        }
        for (int i=0; i<n; i++) {
            maxi=max(maxi, pos[i]);
            ans=max(ans, maxi+t[i]-i);
            pos[t[i]]=max(pos[t[i]], t[i]-i);
        }
        cout << ans << "\n";
    }
    return 0;
}