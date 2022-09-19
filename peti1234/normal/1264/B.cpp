#include <bits/stdc++.h>

using namespace std;
int a, b, c, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    int e=a+c-b-d;
    if (abs(e)>=2) {
        cout << "NO";
        return 0;
    }
    if ((a+b>0 && d>c) || (c+d>0 && a>b)) {
        cout << "NO";
        return 0;
    }
    if (a==0 && b==0) {
        cout << "YES" << "\n";
        if (d>c) cout << 3 << " ";
        for (int i=1; i<=min(c, d); i++) {
            cout << 2 << " " << 3 << " ";
        }
        if (c>d) {
            cout << 2;
        }
        return 0;
    }
    if (c==0 && d==0) {
        cout << "YES" << "\n";
        if (a>b) cout << 0 << " ";
        for (int i=1; i<=min(a, b); i++) {
            cout << 1 << " " << 0 << " ";
        }
        if (b>a) {
            cout << 1;
        }
        return 0;
    }
    cout << "YES" << "\n";
    if (e==-1) {
        for (int i=1; i<=d; i++) {
            cout << 3 << " " << 2 << " ";
        }
        for (int i=1; i<=c-d; i++) {
            cout << 1 << " " << 2 << " ";
        }
        b-=c-d;
        cout << 1 << " ";
        for (int i=1; i<b; i++) {
            cout << 0 << " " << 1 << " ";
        }
    } else if (e==0) {
        for (int i=1; i<=d; i++) {
            cout << 3 << " " << 2 << " ";
        }
        for (int i=1; i<=c-d; i++) {
            cout << 1 << " " << 2 << " ";
        }
        b-=c-d;
        for (int i=1; i<=b; i++) {
            cout << 1 << " " << 0 << " ";
        }
    } else if (e==1) {
        for (int i=1; i<=a; i++) {
            cout << 0 << " " << 1 << " ";
        }
        for (int i=1; i<=b-a; i++) {
            cout << 2 << " " << 1 << " ";
        }
        c-=b-a;
        cout << 2 << " ";
        for (int i=1; i<c; i++) {
            cout << 3 << " " << 2 << " ";
        }
    }
    return 0;
}