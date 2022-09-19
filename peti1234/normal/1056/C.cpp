#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[2001];
int par[2001];
bool v[2001];
int l=0;
int parmaxi=0;
int maxi=0;
int main()
{
    cin >> n >> m;
    n*=2;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        par[a]=b;
        par[b]=a;
    }
    v[0]=true;
    int x;
    cin >> x;
    if (x==2) {
        cin >> l;
        v[l]=true;
    }
    n/=2;
    for (int i=1; i<=n; i++) {
        if (!v[par[l]]) {
            cout.flush() << par[l] << endl;
            v[par[l]]=true;
            cin >> l;
            v[l]=true;
        } else {
            for (int i=1; i<=2*n; i++) {
                if (!v[i]) {
                    if (par[i]!=0) {
                        if (t[i]-t[par[i]]>=t[parmaxi]-t[par[parmaxi]]) {
                            parmaxi=i;
                        }
                    } else {
                        if (t[i]>t[maxi]) {
                            maxi=i;
                        }
                    }
                }
            }
            if (parmaxi!=0) {
                cout.flush() << parmaxi << endl;
                v[parmaxi]=true;
            } else {
                cout.flush() << maxi << endl;
                v[maxi]=true;
            }
            maxi=0, parmaxi=0;
            cin >> l;
            v[l]=true;
        }
    }

    return 0;
}