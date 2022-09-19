#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<string, int> > s;
bool comp(pair<string, int> a, pair<string, int> b) {
    for (int i=0; i<m; i++) {
        if (a.first[i]!=b.first[i]) {
            return (i%2 == a.first[i]>b.first[i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string x;
        cin >> x;
        s.push_back({x, i});
    }
    sort(s.begin(), s.end(), comp);
    for (auto x:s) {
        cout << x.second << " ";
    }
    cout << "\n";
    return 0;
}