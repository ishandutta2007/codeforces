#include <bits/stdc++.h>

using namespace std;
int q, p, fi, el, ism, n;
bool njo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n;
        njo=1, ism=-1;
        cin >> fi, el=fi;
        for (int i=2; i<=n; i++) {
            cin >> p;
            if (p!=el) njo=false;
            else ism=i;
            el=p;
        }
        if (fi==p) ism=n+1;
        if (njo) {
            cout << 1 << "\n";
            for (int i=1; i<=n; i++) cout << 1 << " ";
        } else if (n%2==0) {
            cout << 2 << "\n";
            for (int i=1; i<=n; i++) cout << i%2+1 << " ";
        } else if (ism!=-1) {
            cout << 2 << "\n";
            for (int i=1; i<ism; i++) cout << i%2+1 << " ";
            for (int i=ism; i<=n; i++) cout << (i-1)%2+1 << " ";
        } else {
            cout << 3 << "\n";
            for (int i=1; i<n; i++) cout << i%2+1 << " ";
            cout << 3 << " ";
        }
        cout << "\n";
    }
    return 0;
}
// Knny volt rjnni a lnyegre, utna csak a konstrukcit kellett megadni.