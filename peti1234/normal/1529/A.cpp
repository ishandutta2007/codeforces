#include <iostream>

using namespace std;
int w, n, x, mini, mindb;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        mini=102, mindb=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x<mini) {
                mini=x;
                mindb=0;
            }
            if (x==mini) {
                mindb++;
            }
        }
        cout << n-mindb << "\n";
    }
    return 0;
}