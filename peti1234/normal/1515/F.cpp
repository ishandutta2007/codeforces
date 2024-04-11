#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, m, x, sum[c], ossz, v1[c], v2[c], ki[c], ki2[c], eldb;
set<pair<long long, int> > s;
vector<int> sz[c];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return (ki[a]=holvan(ki[a]));
}
int holvan2(int a) {
    if (!ki2[a]) {
        return a;
    }
    return (ki2[a]=holvan2(ki2[a]));
}
bool unio2 (int a, int b) {
    //cout << "kezd " << a << " " << b << "\n";
    a=holvan2(a), b=holvan2(b);
    //cout << "valt " << a << " " << b << "\n";
    if (a==b) {
        return 0;
    }
    ki2[a]=b;
    return 1;
}
void add(int a) {
    s.insert({-sum[a], a});
}
void torol(int a) {
    s.erase({-sum[a], a});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> x;
    for (int i=1; i<=n; i++) {
        cin >> sum[i];
        ossz+=sum[i];
        add(i);
    }
    for (int i=1; i<=m; i++) {
        int bal, jobb;
        cin >> bal >> jobb;
        v1[i]=bal, v2[i]=jobb;
        if (unio2(bal, jobb)) {
            //cout << "fontos " << i << "\n";
            sz[v1[i]].push_back(i);
            sz[v2[i]].push_back(i);
        }
    }
    //return 0;
    if (x*(n-1)>ossz) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while (eldb<n-1) {
        auto a=*s.begin();
        int id=a.second, elid=sz[id].back();
        sz[id].pop_back();
        int bal=holvan(v1[elid]), jobb=holvan(v2[elid]);
        if (bal!=jobb) {
            cout << elid << "\n";
            eldb++;
            torol(bal), torol(jobb);
            long long uj=sum[bal]+sum[jobb]-x;
            sum[bal]=uj, sum[jobb]=uj;
            int sbal=sz[bal].size(), sjobb=sz[jobb].size();
            if (sbal>sjobb) {
                swap(bal, jobb);
            }
            for (int x:sz[bal]) {
                sz[jobb].push_back(x);
            }
            ki[bal]=jobb;
            add(jobb);
        }
    }
    return 0;
}