#include <bits/stdc++.h>

using namespace std;
int w, n, m;
int ask(int a, int b) {
    cout.flush() << "SCAN " << a << " " << b << "\n";
    int x;
    cin >> x;
    return x;
}
bool pr(int a, int b) {
    cout.flush() << "DIG " << a << " " << b << "\n";
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        int a=ask(1, 1), b=ask(1, m);
        int sor=(a+b-2*(m-1))/2+2, oszlop=(a-b)/2+m+1, fs=sor/2, fo=oszlop/2;
        //cout << "kezd " << sor << " " << oszlop  << "\n";
        int c=ask(fs, 1), d=ask(1, fo);
        int s1=fs-(c+2-oszlop)/2, s2=sor-s1, o1=fo-(d+2-sor)/2, o2=oszlop-o1;
        //cout << "siker " << s1 << " " << s2 << " " << o1 << " " << o2 << "\n";
        if (pr(s1, o1)) {
            pr(s2, o2);
        } else {
            pr(s2, o1);
            pr(s1, o2);
        }
    }
    return 0;
}