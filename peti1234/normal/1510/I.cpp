#include <bits/stdc++.h>

using namespace std;
const int c=1002;
long double po=0.75, bal, jobb, prob;
int ran, ranm=32768;
int n, m, rossz[c], mindb;
bool v[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        bal=jobb=0;
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            v[i]=(c=='1');
            if (!v[i]) {
                bal+=pow(po, rossz[i]-mindb);
            } else {
                jobb+=pow(po, rossz[i]-mindb);
            }
        }
        prob=(bal)/(bal+jobb);
        ran=rand();
        cout.flush() << (ran>=ranm*prob) << "\n";
        cin >> ans;
        mindb=1e9;
        for (int i=1; i<=n; i++) {
            if (v[i]!=ans) {
                rossz[i]++;
            }
            mindb=min(mindb, rossz[i]);
        }
    }
    return 0;
}