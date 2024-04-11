#include <bits/stdc++.h>
 
using namespace std;
const int c=200005;
int n, db[10];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        vector<int> sz;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            x%=10;
            if (db[x]<3) {
                db[x]++;
                sz.push_back(x);
            }
        }
        bool jo=0;
        int si=sz.size();
        for (int i=0; i<si; i++) {
            for (int j=i+1; j<si; j++) {
                for (int k=j+1; k<si; k++) {
                    if ((sz[i]+sz[j]+sz[k])%10==3) {
                        jo=1;
                    }
                }
            }
        }
 
        cout << (jo ? "YES" : "NO") << "\n";
        for (int i=0; i<10; i++) {
            db[i]=0;
        }
    }
 
    return 0;
}
/*
1
16 2
1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
*/