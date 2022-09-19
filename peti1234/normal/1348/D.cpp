#include <bits/stdc++.h>

using namespace std;
int w, n, db, sum;
vector<int> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=1, sum=1, sol.clear();
        while(sum<n) {
            int x=n-sum;
            if (x-db<=db) sol.push_back(x-db);
            else if (x>=4*db) sol.push_back(db);
            else sol.push_back((x-2*db)/2);
            db+=sol.back(), sum+=db;
        }
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}