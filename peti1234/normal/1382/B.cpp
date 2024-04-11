#include <bits/stdc++.h>

using namespace std;
int w, n, db, e;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, db=0, e=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x==1 && e==0) db++;
            if (x!=1) e++;
        }
        if ((db%2)==(db==n)) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}