#include <bits/stdc++.h>
 
using namespace std;
int n;
int a, b, c, d;
int main()
{
    cin >> n >> a >> b >> c >> d;
    while(a!=b && c!=d) {
        if (a==c) {
            cout << "YES";
            return 0;
        }
        if (a!=n) {
            a++;
        } else {
            a=1;
        }
        if (c!=1) {
            c--;
        } else {
            c=n;
        }
    }
    if (a==c) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}