#include <bits/stdc++.h>

using namespace std;
int n, x, maxi;
vector<int> sz;
int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        maxi=max(maxi, x);
        if (sz.size()==0 || x<sz.back()) {
            sz.push_back(x);
        }
        else if (x==sz.back()) {
            sz.pop_back();
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << (sz.size()==0 || sz.size()==1 && sz[0]==maxi ? "YES\n" : "NO\n");
    return 0;
}