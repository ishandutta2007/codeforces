#include <bits/stdc++.h>

using namespace std;
vector<int> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    int q, n;
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n;
        sol.clear();
        int x=sqrt(n);
        for (int i=0; i<=x; i++) {
            sol.push_back(i);
        }
        for (int i=x; i>=1; i--) {
            int y=n/i;
            if (y!=sol.back()) sol.push_back(y);
        }
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}