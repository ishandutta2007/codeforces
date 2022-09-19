#include <bits/stdc++.h>

using namespace std;
const int c=1505;
long long n, ans, ert;
vector<int> sz[c];
int ki[c][2];
int holvan(int a, int b) {
    return (ki[a][b]==a ? a : ki[a][b]=holvan(ki[a][b], b));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=2*n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b-n);
    }
    for (int l=1; l<=n; l++) {
        for (int i=1; i<=n; i++) ki[i][0]=ki[i][1]=i;
        ert=0;
        for (int r=l; r<=n; r++) {
            int a=sz[r][0], b=sz[r][1];
            int ka=holvan(a, 0), kb=holvan(b, 0), va=holvan(a, 1), vb=holvan(b, 1);
            ert+=ka*(n+1-va)+kb*(n+1-vb);
            if (ka>kb) swap(ka, kb);
            if (va<vb) swap(va, vb);
            ki[kb][0]=ka, ki[vb][1]=va;
            ert-=ka*(n+1-va);
            ans+=ert;
        }
    }
    cout << ans << "\n";
    return 0;
}