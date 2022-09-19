#include <bits/stdc++.h>

using namespace std;
int w, n;
int kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    char c;
    cin >> c;
    return (c=='>' ? a : b);
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        vector<int> nagy, kis, ans;
        int e=0, m=0;
        for (int i=1; i<=n; i++) {
            int a=i, b=i+n;
            if (kerd(a, b)!=a) {
                swap(a, b);
            }
            nagy.push_back(a), kis.push_back(b);
        }
        int maxi=kis[0];
        for (int x:kis) {
            if (x==maxi) {
                continue;
            }
            if (kerd(maxi, x)!=maxi) {
                maxi=x;
            }
        }
        e=(maxi>n ? maxi-n : maxi+n);
        maxi=(e==nagy[0] ? nagy[1] : nagy[0]);
        for (int x:nagy) {
            if (x==e || x==maxi) {
                continue;
            }
            if (kerd(maxi, x)!=maxi) {
                maxi=x;
            }
        }
        m=maxi;
        for (int i=1; i<=2*n; i++) {
            if (i==e || i==m) {
                continue;
            }
            for (int j=1; j<=2*n; j++) {
                if (j==i || j==e || j==m) {
                    continue;
                }
                kerd(i, j);
            }
        }
        cout.flush() << "!\n";
    }
    return 0;
}