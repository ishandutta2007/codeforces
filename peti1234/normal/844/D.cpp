#include <bits/stdc++.h>

using namespace std;
const int c=50002, sok=2e9, k=1000;
int n, ert[c], kov[c], lo=-1, up=sok, pos, maxi, mpos, st, x;
void ask(int a) {
    cout.flush() << "? " << a << "\n";
    int p;
    cin >> p >> kov[a];
    ert[a]=p;
    if (kov[a]==-1) kov[a]=a;
    if (p>=x && p<up) {
        up=p;
    }
    if (p<=x && p>lo) {
        lo=p, pos=a;
    }
}
void ans(int a) {
    cout << "! " << a << "\n";
}
int main()
{
    cin >> n >> st >> x, pos=st;
    ask(st);
    for (int i=1; i<k; i++) {
        int a=rand(), b=rand();
        ask((a+b)%n+1);
    }
    for (int i=1; i<k; i++) {
        ask(kov[pos]);
    }
    if (up==sok) {
        ans(-1);
    } else {
        ans(up);
    }
    return 0;
}