#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m;
bool baj;
long long x[c], y[c];
int irany(int a, int b, int c) {
    long long s=(x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
    if (s<0) {
        return -1;
    }
    if (s==0) {
        return 0;
    }
    if (s>0) {
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> x[0] >> y[0];
        int bal=2, jobb=n;
        if (irany(1, jobb, 0)!=1 || irany(1, bal, 0)!=-1) {
            baj=1;
        }
        while (jobb-bal>1) {
            int koz=(bal+jobb)/2;
            if (irany(1, koz, 0)==1) {
                jobb=koz;
            } else {
                bal=koz;
            }
        }
        int s=irany(1, jobb, 0)+2*irany(jobb, bal, 0)+irany(bal, 1, 0);
        if (s<3) {
            baj=1;
        }
    }
    cout << (baj ? "NO" : "YES") << "\n";
    return 0;
}