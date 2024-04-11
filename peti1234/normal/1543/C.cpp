#include <bits/stdc++.h>

using namespace std;
long double s;
long long w, dif, mul=1000000;

map<pair<int, int>, long double> m;
long long read() {
    cin >> s;
    long long ss=s*mul;
    return ss+ss%2;
}

long double solve(int a, int b) {
    //cout << "solve " << a << " " << b << "\n";
    pair<int, int> s={a, b};
    if (m.find(s)==m.end()) {
        long double ans=1;
        long double aa=a, bb=b;
        int sa=a, sb=b;
        if (a) {
            if (sa>=dif) {
                sa-=dif;
                if (sb) {
                    sb+=dif/2;
                }
            } else {
                if (sb) {
                    sb+=sa/2;
                }
                sa=0;
            }
            ans+=aa/mul*solve(sa, sb);
        }
        if (b) {
            sa=a, sb=b;
            if (sb>=dif) {
                sb-=dif;
                if (sa) {
                    sa+=dif/2;
                }
            } else {
                if (sa) {
                    sa+=sb/2;
                }
                sb=0;
            }

            ans+=bb/mul*solve(sa, sb);
        }
        m[s]=ans;
    }
    return m[s];
}
int main()
{
    cin >> w;
    while (w--) {
        int a, b, c;
        a=read(), b=read(), c=read(), dif=read();
        m.clear();
        cout.precision(20);
        cout << solve(a, b) << "\n";
    }
    return 0;
}
/*
1
0.5785 0.2594 0.1621 0.1000
*/