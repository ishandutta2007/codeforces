#include <bits/stdc++.h>

using namespace std;
int t[7];
int a, b, c, d;
int gcd(int a, int b)
{
    if (a>b) {
        swap(a, b);
    }
    if (a==0) {
        return b;
    }
    return gcd(a, b%a);
}
int main()
{
    cout.flush() << "? " << 1 << " " << 2 << endl;
    cin >> a;
    cout.flush() << "? " << 1 << " " << 3 << endl;
    cin >> b;
    cout.flush() << "? " << 1 << " " << 4 << endl;
    cin >> c;
    cout.flush() << "? " << 1 << " " << 5 << endl;
    cin >> d;
    int e=gcd(a, b);
    e=gcd(e, c);
    e=gcd(e, d);
    if (e%15==0 || e%23==0) {
        while(e%2==0) {
            e/=2;
        }
    }

    t[1]=e;
    t[2]=a/e;
    t[3]=b/e;
    t[4]=c/e;
    t[5]=d/e;
    t[6]=7418880;
    for (int i=1; i<=5; i++) {
        t[6]/=t[i];
    }
    cout << "! ";
    for (int i=1; i<=6; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    return 0;
}