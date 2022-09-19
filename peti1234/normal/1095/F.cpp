#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, a[c], ki[c], pos=1, sum;
vector<pair<long long, pair<int, int> > > el;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]<a[pos]) pos=i;
    }
    for (int i=1; i<=n; i++) {
        if (i!=pos) {
            el.push_back({a[i]+a[pos], {i, pos}});
        }
    }
    for (int i=1; i<=m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        el.push_back({c, {a, b}});
    }
    sort(el.begin(), el.end());
    for (auto x:el) {
        if (unio(x.second.first, x.second.second)) {
            sum+=x.first;
        }
    }
    cout << sum << "\n";
    return 0;
}