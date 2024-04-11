#include <bits/stdc++.h>

using namespace std;
int w, n;
void p(int a) {
    if (a>n) return;
    cout << a+1 << " " << a+3 << " " << a << " " << a+2 << " ";
    p(a+4);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        if (n<4) cout << -1 << "\n";
        else {
            if (n%4==0) p(1);
            if (n%4==1) cout << 1 << " ", p(2);
            if (n%4==2) cout << 1 << " " << 3 << " " << 6 << " " << 4 << " " << 2 << " " << 5 << " ", p(7);
            if (n%4==3) cout << 1 << " " << 3 << " " << 6 << " " << 4 << " " << 2 << " " << 5 << " " << 7 << " ", p(8);
        }
    }
    return 0;
}