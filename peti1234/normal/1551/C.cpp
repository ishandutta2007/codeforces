#include <bits/stdc++.h>

using namespace std;
int w, n, maxi, db[5];
vector<int> sz[5];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            int si=s.size();
            for (int i=0; i<5; i++) {
                db[i]=0;
            }
            for (auto x:s) {
                db[x-'a']++;
            }
            for (int i=0; i<5; i++) {
                sz[i].push_back(2*db[i]-si);
            }
        }
        for (int i=0; i<5; i++) {
            sort(sz[i].rbegin(), sz[i].rend());
            int sum=0, db=0;
            for (auto x:sz[i]) {
                if (sum+x>0) {
                    sum+=x, db++;
                }
            }
            maxi=max(maxi, db);
        }
        cout << maxi << "\n";
        for (int i=0; i<5; i++) {
            sz[i].clear();
        }
        maxi=0;
    }
    return 0;
}