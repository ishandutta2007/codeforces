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
        int p=1;
        while(n>0) {
            if (n%10) sol.push_back((n%10)*p);
            n/=10, p*=10;
        }
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}