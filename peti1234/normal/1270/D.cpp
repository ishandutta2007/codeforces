#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
int n, k, pos, ert, pos2, ert2, db;
pii h;
bool v[502];
vector<int> sz;
pii kerd() {
    cout << "? ";
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
    cout.flush() << "\n";
    int a, b;
    cin >> a >> b;
    return {a, b};
}
int main()
{
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        v[i]=1;
    }
    h=kerd();
    pos=h.first, ert=h.second;
    v[pos]=0, v[k+1]=1;
    h=kerd();
    pos2=h.first, ert2=h.second;
    v[pos]=1;
    for (int i=1; i<=k; i++) {
        if (i!=pos) {
            v[i]=0;
            h=kerd();
            int se=h.second;
            if ((ert2<ert && se==ert) || (ert2>ert && se!=ert)) {
                db++;
            }
            v[i]=1;
        }
    }
    cout << "! " << db+1 << "\n";
    return 0;
}