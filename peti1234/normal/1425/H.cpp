#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, c, d, m, n, k;
void jo() {
    cout << "Ya ";
}
void nj() {
    cout << "Tidak ";
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        m=a+b, n=a+d, k=b+c;
        if (m%2) {
            if (n) jo();
            else nj();
            if (k) jo();
            else nj();
            nj();
            nj();
        } else {
            nj();
            nj();
            if (k) jo();
            else nj();
            if (n) jo();
            else nj();
        }
        cout << "\n";
    }
    return 0;
}