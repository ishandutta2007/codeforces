#include <bits/stdc++.h>

using namespace std;
const int c=205;
int w, n, p[c], pp[c], ans[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (!v[p[a]]) {
        dfs(p[a]);
    }
}
void check() {
    int sum=0;
    for (int i=1; i<n; i++) {
        sum+=abs(ans[i]-pp[ans[i+1]]);
    }
    sum+=abs(ans[n]-pp[ans[1]]);
    //cout << sum << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            pp[i]=p[i];
        }
        while (true) {
            dfs(1);
            bool baj=0;
            for (int i=1; i<n; i++) {
                if (v[i] && !v[i+1] && !baj) {
                    baj=1;
                    for (int j=1; j<=n; j++) {
                        if (p[j]==i+1) p[j]=i;
                        else if (p[j]==i) p[j]=i+1;
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                v[i]=0;
            }
            if (!baj) {
                break;
            }
        }
        ans[1]=p[1];
        int el=p[1];
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (p[j]==el) {
                    ans[i]=j;
                    el=j;
                    break;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        //check();
    }
    return 0;
}