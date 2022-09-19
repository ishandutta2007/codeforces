#include <bits/stdc++.h>

using namespace std;
int w, db;
long long n, po=2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=0, po=2;
        while(n>=po*(po-1)/2) n-=(po-1)*po/2, db++, po*=2;
        cout << db << "\n";
    }
    return 0;
}