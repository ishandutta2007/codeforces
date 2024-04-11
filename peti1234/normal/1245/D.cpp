#include <bits/stdc++.h>

using namespace std;
const int c=2005;
long long n, x[c], y[c], ki[c], k[c], ans;
vector<pair<long long, pair<int, int> > > el;
vector<int> s;
vector<pair<int, int> > s2;

int holvan(int a) {
    return (!ki[a] ? a : ki[a]=holvan(ki[a]));
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=1; i<=n; i++) {
        long long ert;
        cin >> ert;
        el.push_back({ert, {n+1, i}});
    }
    for (int i=1; i<=n; i++) {
        cin >> k[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            long long val=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            el.push_back({val, {i, j}});
        }
    }

    sort(el.begin(), el.end());
    for (auto x:el) {
        int a=x.second.first, b=x.second.second;
        if (holvan(a)!=holvan(b)) {
            unio(a, b);
            ans+=x.first;
            if (a==n+1) {
                s.push_back(b);
            } else {
                s2.push_back({a, b});
            }
        }
    }
    cout << ans << "\n";
    cout << s.size() << "\n";
    for (auto x:s) {
        cout << x << " ";
    }
    cout << "\n";
    cout << s2.size() << "\n";
    for (auto x:s2) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}