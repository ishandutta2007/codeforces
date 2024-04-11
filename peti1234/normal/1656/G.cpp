#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], par[c], ans[c], res[c], ut[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    int p=par[a], ap=ans[p];
    if (!ap) {
        ans[a]=p;
    } else {
        ans[a]=n+1-a;
    }
    if (!v[ans[a]]) {
        dfs(ans[a]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }

        int db=0, spec=0, koz=0;
        if (n%2) {
            koz=n/2+1;
            ut[t[koz]]=koz;
        }
        for (int i=1; i<=n; i++) {
            if (i==koz) continue;
            int s=ut[t[i]];
            if (s) {
                par[i]=s, par[s]=i;
                ut[t[i]]=0;
                db++;
            } else {
                ut[t[i]]=i;
            }
        }
        for (int i=1; i<=n; i++) {
            if (ut[i]) {
                spec=ut[i];
            }
        }

        if (spec) {
            par[par[koz]]=spec;
            par[spec]=par[koz];

            par[koz]=koz, ans[koz]=koz;
        }
        
        if (n/2!=db || n%2 && spec==koz) {
            cout << "NO\n";
        } else {

            dfs(1);
            for (int i=1; i<=n; i++) {
                if (i!=koz && !v[i]) {
                    dfs(i);
                    int A=1, B=ans[A], C=par[A], D=ans[C], E=i, F=ans[E], G=par[E], H=ans[G];
                    // ABCD..., EFGH... -> AFGBCHED...
                    ans[A]=F;
                    ans[G]=B;
                    ans[C]=H;
                    ans[E]=D;
                }
            }

            if (spec) {
                swap(ans[spec], ans[koz]);
            }

            for (int i=1; i<=n; i++) {
                res[ans[i]]=i;
            }

            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
        for (int i=1; i<=n; i++) {
            t[i]=0, par[i]=0, ans[i]=0, ut[i]=0, v[i]=0, res[i]=0;
        }
        spec=0, koz=0;
    }
    return 0;
}