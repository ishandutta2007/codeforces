#include <bits/stdc++.h>

using namespace std;

vector<int> sz[100001];
vector<int> sor;
bool volt[100001];
int szint[100001];
int sk=0;
int n, m;
vector <int> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y);
        sz[y].push_back(x);
    }

    for (int i=1; i<=n; i++) {
        if (!volt[i]){
            sor.push_back(i);
            volt[i]=true;
            while (sk<sor.size()) {
                int akt=sor[sk];
                sk++;
                for (int s : sz[akt]) {
                    if (!volt[s]) {
                        sor.push_back(s);
                        volt[s]=true;
                        szint[s]=szint[akt]+1;
                    }
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int s: sz[i]) {
            if (szint[i]%2==szint[s]%2) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (szint[i]%2==0) a.push_back(i);
        else b.push_back(i);
    }
    cout << a.size() << endl;
    for (int x :a) cout << x << " ";

    cout << endl << b.size() << endl;
    for (int x :b) cout << x << " ";

    return 0;
}