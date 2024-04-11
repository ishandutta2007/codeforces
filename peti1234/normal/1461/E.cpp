#include <bits/stdc++.h>

using namespace std;
long long ert, kis, nagy, nap, pl, mi, db, s;
bool v[1000002], sp;
void vege(int x) {
    if (!sp) {
        if (!x) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
        sp=1;
    }
}
int main()
{
    cin >> ert >> kis >> nagy >> nap >> mi >> pl;
    ert-=kis, nagy-=kis, kis=0;
    s=ert+pl-nagy;
    if (pl<mi) {
        if (ert+pl>nagy) ert-=pl;
        vege((ert-kis)/(mi-pl)>=nap);
    }
    while(!sp) {
        db=(ert)/mi;
        nap-=db, ert-=db*mi;
        if (v[ert] || nap<=0) vege(1);
        v[ert]=1;
        ert+=pl;
        if (ert>nagy) vege(0);
    }
    return 0;
}