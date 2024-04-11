#include <bits/stdc++.h>

using namespace std;
string a, b, c;
int k, id;
bool ua(string a, string b) {
    return a==b;
}
bool ko(string a, string b) {
    int x=abs(a[0]-b[0]);
    return (a[1]==b[1] && x>0 && x<=2);
}
int main()
{
    cin >> a >> b >> c;
    id=ua(a, b)+ua(a, c)+ua(b, c);
    k=ko(a, b)+ko(a, c)+ko(b, c);
    if (id==3 || k==3) cout << 0 << "\n";
    else if (id || k) cout << 1 << "\n";
    else cout << 2 << "\n";
    return 0;
}