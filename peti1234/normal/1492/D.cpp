#include <bits/stdc++.h>

using namespace std;
int a, b, k;
string s;
int main()
{
    cin >> a >> b >> k;
    if (((a==0 || b==1) && k) || k==a+b || (k>1 && k==a+b-1)) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i=0; i<b; i++) {
        s+='1';
    }
    for (int i=0; i<a; i++) {
        s+='0';
    }
    cout << s << "\n";
    if (k<b) {
        swap(s[b-k], s[b]);
    } else {
        swap(s[1], s[k+1]);
    }
    cout << s << "\n";
    return 0;
}