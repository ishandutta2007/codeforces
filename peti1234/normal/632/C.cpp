#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> s;
bool comp(string a, string b) {
    return (a+b<b+a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        string x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end(), comp);
    for (auto x:s) {
        cout << x;
    }
    return 0;
}