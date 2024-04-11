#include <bits/stdc++.h>

using namespace std;
long long n, k, m;
long long e=0, v, l=0,  p;
vector<pair<int, int> > t;
int main()
{
    cin >> n >> k >> m;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (t.size()==0 || a!=t.back().first) {
            t.push_back({a, 1});
        } else {
            t.back().second++;
            if (t.back().second==k) {
                t.pop_back();
            }
        }
    }
    v=t.size()-1;
    for (int i=0; i<t.size(); i++) {
        p+=t[i].second;
    }
    while (v>e) {
        if (t[e].first!=t[v].first || t[e].second+t[v].second<k) {
            break;
        }
        l++;
        if (t[e].second+t[v].second!=k) {
            break;
        }
        e++;
        v--;
    }
    if (e>v) {
        cout << 0;
        return 0;
    }
    if (e==v) {
        cout << (t[e].second*m%k!=0 ? t[e].second*m%k+l*k : 0);
        return 0;
    }
    cout << p*m-l*k*(m-1);
    return 0;
}