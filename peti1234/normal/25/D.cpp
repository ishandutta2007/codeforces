#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, ki[c];
vector<pair<int, int> > regi, uj;
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a==b) return true;
    ki[a]=b;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        if (unio(a, b)) regi.push_back({a, b});
    }
    for (int i=2; i<=n; i++) {
        if (!unio(01, i)) uj.push_back({1, i});
    }
    int si=regi.size();
    cout << si << "\n";
    for (int i=0; i<si; i++) {
        cout << regi[i].first << " " << regi[i].second << " " << uj[i].first << " " << uj[i].second << "\n";
    }
    return 0;
}