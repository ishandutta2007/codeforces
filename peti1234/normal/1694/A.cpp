#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        for (int i=0; i<min(a, b); i++) {
            cout << 10;
        }
        for (int i=0; i<a-b; i++) cout << 0;
        for (int i=0; i<b-a; i++) cout << 1;
        cout << "\n";
    }
    return 0;
}