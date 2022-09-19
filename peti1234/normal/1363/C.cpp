#include <bits/stdc++.h>

using namespace std;
int w, n, x, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> x, db=0;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            db+=(x==a), db+=(x==b);
        }
        if (n==1 || db==1 || n%2==0) cout << "Ayush\n";
        else cout << "Ashish\n";
    }
    return 0;
}