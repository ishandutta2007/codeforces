#include <bits/stdc++.h>

using namespace std;
int a;
int b;
char d;
int c;

int main()
{
    cin >> a;
    cin >> b;
    cin >> d;
    cin >> c;
    if (c>59 ) {

        c=20+c%10;
    }


    if (a==24 && b>=24) {
        b=b%10+10;
    }

    if (a==12 && b>12 && b%10!=0) {
        b=b%10;
    }
    if (a==12 && b%10==0) {
        b=10;
    }
    if (b<10) {
        cout << 0;
    }
    cout << b;
    cout << d;
    if (c<10) {
        cout << 0;
    }
    cout << c;

    return 0;
}