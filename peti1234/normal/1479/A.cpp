#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, kis, nagy, koz, t[c];
void ask(int a) {
    cout.flush() << "? " << a << "\n";
    cin >> t[a];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    nagy=n+1, koz=(kis+nagy)/2;
    t[kis]=n+1, t[nagy]=n+1;
    ask(koz);
    while (nagy-kis>2) {
        //cout << "alap " << kis << " " << koz << " " << nagy << "\n";
        int uj;
        if (koz-kis>nagy-koz) {
            uj=(koz+kis)/2;
            ask(uj);
            if (t[uj]>t[koz]) {
                kis=uj;
            } else {
                nagy=koz;
                koz=uj;
            }
        } else {
            uj=(nagy+koz)/2;
            ask(uj);
            if (t[uj]>t[koz]) {
                nagy=uj;
            } else {
                kis=koz;
                koz=uj;
            }
        }
    }
    cout.flush() << "! " << koz << "\n";
    return 0;
}