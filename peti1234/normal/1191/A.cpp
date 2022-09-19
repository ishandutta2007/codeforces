#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int x=a%4;
    if (x==1) {
        cout << 0 << " " << 'A' << endl;
    }
    if (x==0) {
        cout << 1 << " " << 'A' << endl;
    }
    if (x==3) {
        cout << 2 << " " << 'A' << endl;
    }
    if (x==2) {
        cout << 1 << " " << 'B' << endl;
    }
    return 0;
}