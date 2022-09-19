#include <bits/stdc++.h>

using namespace std;
long long w, n, po[61];
vector<int> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=2;
    for (int i=1; i<=60; i++) po[i]=po[i-1]*2+2;
    cin >> w;
    while(w--) {
        cin >> n;
        if (n%2) cout << -1 << "\n";
        else {
            sol.clear(), sol.push_back(1), n-=2;
            for (int i=60; i>=0; i--) {
                while(n>=po[i]) {
                    n-=po[i];
                    for (int j=0; j<i; j++) sol.push_back(0);
                    sol.push_back(1);
                }
            }
            cout << sol.size() << "\n";
            for (int x:sol) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}