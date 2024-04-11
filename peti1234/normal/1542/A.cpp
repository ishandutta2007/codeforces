#include <iostream>

using namespace std;
int w, n, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        db=0;
        for (int i=0; i<2*n; i++) {
            int x;
            cin >> x;
            db+=(x%2);
        }
        cout << (db==n ? "Yes" : "No") << "\n";
    }
    return 0;
}