#include <iostream>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x=i;
            if (x<=n-2) {
                if (n%2==0) {
                    if (x%2) x++;
                    else x--;
                } else {
                    if (x>1 && x%2) x--;
                    else if (x>1) x++;
                }
            }
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}