#include <bits/stdc++.h>

using namespace std;
long long a1, b1, a2, b2, L, R, sok=2e10;
int main()
{
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    if (a1<a2) {
        swap(a1, a2);
        swap(b1, b2);
    }
    b1+=sok, b2+=sok, L+=sok, R+=sok;
    if (a1>1e6) {
        long long db=0;
        for (long long ert=b1; ert<=R; ert+=a1) {
            if (L<=ert && ert-b2>=0 && (ert-b2)%a2==0) {
                db++;
            }
        }
        cout << db << "\n";
    } else {
        long long s=a1*a2/__gcd(a1, a2), fix=-1;
        for (long long ert=b1; ert<=min(R, b1+a1*a1); ert+=a1) {
            if ((ert-b2)%a2==0) {
                fix=(ert%s+s)%s;
                L=max({L, ert, b2});
                break;
            }
        }
        if (fix==-1 || L>R) {
            cout << 0 << "\n";
            return 0;
        }
        cout << (R-fix)/s-(L-fix-1)/s << "\n";
        int db=1;

    }
    return 0;
}