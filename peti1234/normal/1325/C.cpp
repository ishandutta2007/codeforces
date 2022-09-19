#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, cnt=3, db[100002];
vector<pair<int, int> > sz;
bool e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        db[a]++, db[b]++, sz.push_back({a, b});
    }
    for (int i=0; i<n-1; i++) {
        int fi=sz[i].first, se=sz[i].second;
        if (db[fi]==1) c=fi;
        if (db[se]==1) c=se;
        if (c>b) swap(b, c);
        if (c>a) swap(c, a);
    }
    if (!c) {
        for (int i=0; i<n-1; i++) cout << i << " ";
        return 0;
    }
    for (int i=0; i<n-1; i++) {
        int fi=sz[i].first, se=sz[i].second;
        if (fi==a || se==a) cout << 0;
        else if (fi==b || se==b) cout << 1;
        else if (fi==c || se==c) cout << 2;
        else cout << cnt, cnt++;
        cout << "\n";
    }
    return 0;
}