#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x==y) {
        cout << '=' << endl;
        return 0;
    }
    if (x==1) {
        cout << '<' << endl;
        return 0;
    }
    if (y==1) {
        cout << '>' << endl;
        return 0;
    }
    if (min(x, y)==2 && max(x, y)==4) {
        cout << '=' << endl;
        return 0;
    }
    if (x==2 && y==3) {
        cout << '<' << endl;
        return 0;
    }
    if (x==3 && y==2) {
        cout << '>' << endl;
        return 0;
    }
    if (x>y) {
        cout << '<' << endl;
        return 0;
    }
    cout << '>' << endl;
    return 0;
}