#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, fel, p[c], inv_p[c];
vector<pair<int, int> > valasz;
int csere(int a, int b) {
    valasz.push_back({a, b});
    swap(p[a], p[b]);
    swap(inv_p[p[a]], inv_p[p[b]]);
}
void valt(int a) {
    if (inv_p[a]>fel) {
        csere(inv_p[a], 1);
    } else {
        csere(inv_p[a], n);
    }
    if (abs(inv_p[a]-a)<fel) {
        csere(1, n);
    }
    csere(inv_p[a], a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fel=n/2;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        inv_p[p[i]]=i;
    }
    for (int i=fel; i>=1; i--) {
        valt(i), valt(n+1-i);
    }
    cout << valasz.size() << "\n";
    for (auto v:valasz) {
        cout << v.first << " " << v.second << "\n";
    }
    return 0;
}