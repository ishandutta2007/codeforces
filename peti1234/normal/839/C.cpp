#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> sz[100001];
double v[100001];
bool j[100001];
void melysegi(int a)
{
    j[a] = true;
    for (int i = 0; i < sz[a].size(); i++) {
        if (!j[sz[a][i]]) {
            melysegi(sz[a][i]);
            v[a] += v[sz[a][i]];
        }
    }
    if (a == 1) {
        //cout << v[a] << endl;
        v[a] /= sz[a].size();
        v[a]++;
        return;
    }
    if (sz[a].size() == 1) {
        v[a] = 0;
        return;
    }
    v[a] /= (sz[a].size() - 1);
    v[a]++;
    return;
}
int main()
{
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y);
        sz[y].push_back(x);
    }
    melysegi(1);
    /*for (int i=1; i<=n; i++) {
    cout << i << " " << v[i] << endl;
    }*/
    cout << setprecision(10) << v[1] << endl;
    return 0;
}