#include <bits/stdc++.h>

using namespace std;
const int c=10000005;
vector<pair<int, int> > sz[c];
int n, a[c], b[c], xx, yy;
bool v[c];
long long ans=1e15;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (!v[x]) a[x]=i;
        else b[x]=i;
        v[x]=1;
        x=1;
    }
    for (int i=1; i<c; i++) {
        int aa=0, bb=0;
        long long ert=i;
        for (int j=i; j<c; j+=i) {
            if (v[j]) {
                if (!aa) {
                    aa=a[j];
                    ert*=j/i;
                } else {
                    bb=a[j];
                    ert*=j/i;
                }
                if (!bb && b[j]) {
                    bb=b[j];
                    ert*=j/i;
                }
                if (bb) {
                    if (ert<ans) {
                        ans=ert;
                        xx=aa, yy=bb;
                    }
                    break;
                }
            }
        }
    }
    if (xx>yy) swap(xx, yy);
    cout << xx << " " << yy << "\n";
    return 0;
}