#include <bits/stdc++.h>

using namespace std;
const int c=600002;
int t[c], inv[c], be[c], po[4], ki, n, m, k;
vector<int> sz[c], sol;
bool baj;
string s;
queue<int> q;
int ert(char c) {
    int s=c-'a'+1;
    if (1<=s && s<=26) {
        return s;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    po[0]=1;
    for (int i=1; i<k; i++) {
        po[i]=27*po[i-1];
    }
    for (int i=1; i<=n; i++) {
        cin >> s;
        int sum=0;
        for (int i=0; i<k; i++) {
            sum+=po[i]*ert(s[i]);
        }
        t[sum]=i;
        inv[i]=sum;
    }
    for (int i=1; i<=m; i++) {
        cin >> s >> ki;
        bool sp=0;
        for (int mask=0; mask<(1<<k); mask++) {
            int sum=0, pos;
            for (int i=0; i<k; i++) {
                if (mask & (1<<i)) {
                    sum+=po[i]*ert(s[i]);
                }
            }
            pos=t[sum];
            if (pos) {
                if (pos==ki) {
                    sp=1;
                } else {
                    sz[ki].push_back(pos);
                    be[pos]++;
                }
            }
        }
        if (!sp) {
            baj=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!be[i]) {
            q.push(i);
        }
    }
    while (q.size()>0) {
        int a=q.front();
        q.pop();
        sol.push_back(a);
        for (int x:sz[a]) {
            be[x]--;
            if (!be[x]) {
                q.push(x);
            }
        }
    }
    if (sol.size()!=n) {
        baj=1;
    }
    if (baj) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i:sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}