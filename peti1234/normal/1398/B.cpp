#include <bits/stdc++.h>

using namespace std;
int w, n, sum, db;
vector<int> sol;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), sum=0, db=0, sol.clear();
        for (int i=0; i<n; i++) {
            if (s[i]=='0') sol.push_back(db), db=0;
            else db++;
        }
        sol.push_back(db);
        sort(sol.rbegin(), sol.rend());
        for (int i=0; i<sol.size(); i++) if (i%2==0) sum+=sol[i];
        cout << sum << " ";
    }
    return 0;
}