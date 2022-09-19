#include <bits/stdc++.h>

using namespace std;
int w, n, k;
bool p;
string s;
int vel() {
    long long x=rand(), y=rand(), z=rand();
    return (x*y+z)%n+1;
}
void val(int a) {
    cout.flush() << "! " << a << "\n";
}
bool ek(int a) {
    cout.flush() << "? " << 1 << " " << 1 << "\n" << 1 << "\n" << a << "\n";
    cin >> s;
    return s=="SECOND";
}
bool mk(int a, int b) {
    cout.flush() << "? " << a << " " << a << "\n";
    for (int i=b-a; i<b; i++) cout << i << " ";
    cout << "\n";
    for (int i=b; i<b+a; i++) cout << i << " ";
    cout.flush() << "\n";
    cin >> s;
    return s=="FIRST";
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k, p=0;
        for (int i=1; i<=28; i++) {
            int a=vel();
            if (!p && a!=1) if (ek(a)) val(1), p=1;
        }
        if (!p) {
            int l=1, h=n;
            while(h-l>1) {
                int m=min((h+l)/2, 2*l);
                if (mk(m-l, l+1)) h=m;
                else l=m;
            }
            val(h);
        }
    }
    return 0;
}