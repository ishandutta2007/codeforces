#include <bits/stdc++.h>

using namespace std;
int n, si;
string s, ans;
int main()
{
    cin >> n >> s;
    for (auto x:s) {
        if (si%2==0 || x!=ans.back()) {
            ans+=x;
            si++;
        }
    }
    if (si%2) {
        ans.pop_back();
        si--;
    }
    cout << n-si << "\n" << ans << "\n";
    return 0;
}