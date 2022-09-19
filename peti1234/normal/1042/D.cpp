#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, ert, sum, x, pos, ans, id[c], kezd[c], fen[c];
vector<pair<long long, int> > sz;
int lsb(int a) {
    return (a & -a);
}
void add(int a) {
    while (a<=n) {
        fen[a]++;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> ert;
    sz.push_back({0, 1});
    for (int i=2; i<=n+1; i++) {
        int x;
        cin >> x;
        sum+=x;
        sz.push_back({sum, i});
    }
    n++;
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        int p=sz[i].second;
        //cout << p << " " << sz[i].first << "\n";
        id[p]=i+1;
        while (pos<n && sz[i].first-sz[pos].first>=ert) {
            pos++;
        }
        kezd[p]=pos;
        //cout << "fontos " << kezd[p] << "\n";
    }
    for (int i=1; i<=n; i++) {
        ans+=i-1-ask(kezd[i]);
        add(id[i]);
    }
    cout << ans << "\n";
    return 0;
}