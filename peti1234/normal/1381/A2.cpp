#include <bits/stdc++.h>

using namespace std;
int n, w;
string a, b;
vector<int> sol;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> a >> b, sol.clear();
        for (int i=0; i<n; i++) {
            if ((i%2==0 && a[i/2]==b[n-i-1]) || (i%2==1 && a[n-i/2-1]!=b[n-i-1])) sol.push_back(1);
            sol.push_back(n-i);
        }
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}