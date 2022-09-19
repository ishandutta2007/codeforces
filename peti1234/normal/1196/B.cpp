#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b;
        vector<int> v;
        cin >> a >> b;
        int o=0;
        vector<int> r;
        for (int i=0; i<a; i++) {
            int x;
            cin >> x;
            if (x%2!=0) {
                o++;
                if (r.size()<b-1) {
                    r.push_back(i+1);
                }
            }
            v.push_back(x);
        }
        bool q=true;
        if (o%2!=b%2 || o<b) {
            q=false;
        }
        if (!q) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            for(int i=0; i<r.size(); i++) {
                cout << r[i] << " ";
            }
            cout << a << "\n";
        }
    }
    return 0;
}