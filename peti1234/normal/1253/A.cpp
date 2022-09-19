#include <bits/stdc++.h>
 
using namespace std;
int t[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int k=0;
        bool c=false;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            int a=x-t[i];
            if (a<0) {
                c=true;
            }
            if (k!=0) {
                if (a==0) {
                    k=1001;
                } else if (a!=k) {
                    c=true;
                }
            } else {
                k=a;
            }
        }
        if (c) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
    }
    return 0;
}