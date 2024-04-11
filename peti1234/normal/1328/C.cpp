#include <bits/stdc++.h>

using namespace std;
string a, b, c;
int w, n;
bool p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> c;
        a.clear(), b.clear(), p=0;
        for (int i=0; i<n; i++) {
            char x=c[i];
            if (p) a+='0', b+=x;
            else {
                if (x=='0') a+=x, b+=x;
                if (x=='2') a+='1', b+='1';
                if (x=='1') a+='1', b+='0', p=true;
            }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}
// Knny volt.