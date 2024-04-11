#include <bits/stdc++.h>

using namespace std;
const int c=62;
int t[c], pos[c], n, k, cnt;
vector<int> sz, sol[c];
void add(int a) {
    sz.push_back(a);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i], pos[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            if (pos[j]<pos[j-1]) {
                sz.clear();
                if (pos[j]>1) add(pos[j]-1);
                int sp=0;
                add(1);
                for (int k=pos[j]+1; k<=n; k++) {
                    if (t[k]==t[k-1]+1) sp++;
                    else break;
                }
                sz.back()+=sp;
                add(pos[j-1]-pos[j]-sp);
                if (pos[j-1]!=n) add(n-pos[j-1]);
                cnt++;
                sol[cnt].push_back(sz.size());
                for (int i=0; i<sz.size(); i++) sol[cnt].push_back(sz[i]);
                reverse(t+1, t+n+1);
                reverse(sz.begin(), sz.end());
                int sum=1;
                for (int i=0; i<sz.size(); i++) {
                    reverse(t+sum, t+sum+sz[i]);
                    sum+=sz[i];
                }
                for (int i=1; i<=n; i++) pos[t[i]]=i;
                break;
            }
        }
    }
    cout << cnt << "\n";
    for (int i=1; i<=cnt; i++) {
        for (int j=0; j<sol[i].size(); j++) cout << sol[i][j] << " ";
        cout << "\n";
    }
    return 0;
}