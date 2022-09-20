#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sol.clear();
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            int si=sol.size();
            while(si>=2 && (x>=sol[si-1] && sol[si-1]>=sol[si-2] || x<=sol[si-1] && sol[si-1]<=sol[si-2])) sol.pop_back(), si--;
            if (!si || x!=sol.back()) sol.push_back(x);
        }
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}