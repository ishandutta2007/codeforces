#include <bits/stdc++.h>

using namespace std;
int n, k;
string s, r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    for (auto p:s) {
        int ert=p-'a', dif=min({k, max(ert, 25-ert)});
        k-=dif;
        if (ert>=dif) r+=p-dif;
        else r+=p+dif;
    }
    cout << (k ? "-1" : r) << "\n";
    return 0;
}