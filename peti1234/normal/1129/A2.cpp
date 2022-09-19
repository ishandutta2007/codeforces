#include <bits/stdc++.h>

using namespace std;
int n, m;
int mini[5001];
int k[5001];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        mini[i]=i+n;
        k[i]-=n;
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        k[a]+=n;
        if (b<a) {
            b+=n;
        }
        mini[a]=min(mini[a], b);
    }
    for (int i=1; i<=n; i++) {
        int maxi=0;
        for (int j=1; j<=n; j++) {
            int p=0;
            p=j-i;
            if (p<0) {
                p+=n;
            }
            p+=k[j];
            p+=mini[j]-j;
            if (k[j]!=-n) {
            maxi=max(maxi, p);
            }
        }
        cout << maxi << " ";
    }
    return 0;
}