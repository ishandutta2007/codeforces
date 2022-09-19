#include <bits/stdc++.h>

using namespace std;
int main()
{
    while(true) {
        int k, x;
        cout.flush() << "next" << " " << 0 << " " << 1 << "\n";
        cin >> k;
        for (int i=1; i<=k; i++) {
            string s;
            cin >> s;
        }
        cout.flush() << "next" << " " << 0 << "\n";
        cin >> x;
        for (int i=1; i<=x; i++) {
            string s;
            cin >> s;
        }
        if (x==2) {
            break;
        }
    }
    while(true) {
        cout.flush() << "next" << " ";
        for (int i=0; i<10; i++) {
            cout.flush() << i << " ";
        }
        cout.flush() << "\n";
        int k;
        cin >> k;
        for (int i=0; i<k; i++) {
            string s;
            cin >> s;
        }
        if (k==1) {
            cout.flush() << "done" << "\n";
            break;
        }
    }
    return 0;
}