#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        if (a==1) {
            if (b==1) {
                cout << "Yes";
            } else {
                cout << "NO";
            }
        } else if (a<=3) {
            if (b<=3) {
                cout << "Yes";
            } else {
                cout << "No";
            }
        } else {
            cout << "Yes";
        }
        cout << "\n";
    }
    return 0;
}