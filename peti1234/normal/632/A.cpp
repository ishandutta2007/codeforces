#include <bits/stdc++.h>

using namespace std;
long long n, db, ert;
vector<bool> v;
int main()
{
    cin >> n >> ert;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        v.push_back(s=="halfplus");
    }
    reverse(v.begin(), v.end());
    for (auto x:v) {
        db=2*db+x;
    }
    cout << (2*db-__builtin_popcountll(db))*ert/2 << "\n";
    return 0;
}