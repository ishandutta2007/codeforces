#include <bits/stdc++.h>

using namespace std;
void p(int a, int b) {
    cout << a << " " << b << "\n";
}
void u(int a, int b) {
    for (int i=a; i<b; i++) p(i, i+1);
}
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    swap(b, c);
    int s=a+b+c, maxi=max({a, b, c});
    if (2*maxi>s || s%2 || s>2*n-2) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if (2*maxi==s) {
        int pos=4;
        if (a==maxi) {
            if (b==1) {
                p(1, 3);
            } else {
                p(1, pos);
                u(pos, pos+b-2);
                p(pos+b-2, 3);
                pos+=b-1;
            }

            if (c==1) {
                p(2, 3);
            } else {
                p(2, pos);
                u(pos, pos+c-2);
                p(pos+c-2, 3);
                pos+=c-1;
            }
        }
        if (b==maxi) {
            if (a==1) {
                p(1, 2);
            } else {
                p(1, pos);
                u(pos, pos+a-2);
                p(pos+a-2, 2);
                pos+=a-1;
            }

            if (c==1) {
                p(2, 3);
            } else {
                p(2, pos);
                u(pos, pos+c-2);
                p(pos+c-2, 3);
                pos+=c-1;
            }
        }
        if (c==maxi) {
            if (a==1) {
                p(1, 2);
            } else {
                p(1, pos);
                u(pos, pos+a-2);
                p(pos+a-2, 2);
                pos+=a-1;
            }

            if (b==1) {
                p(1, 3);
            } else {
                p(1, pos);
                u(pos, pos+b-2);
                p(pos+b-2, 3);
                pos+=b-1;
            }

        }
        u(pos-1, n);
    } else {
        int s=(a+b+c)/2;
        int ert=4;
        if (s-c>1) {
            int kov=ert+s-c-2;
            p(1, ert);
            u(ert, kov);
            p(kov, n);
            ert=kov+1;
        } else {
            p(1, n);
        }

        if (s-b>1) {
            int kov=ert+s-b-2;
            p(2, ert);
            u(ert, kov);
            p(kov, n);
            ert=kov+1;
        } else {
            p(2, n);
        }

        if (s-a>1) {
            int kov=ert+s-a-2;
            p(3, ert);
            u(ert, kov);
            p(kov, n);
            ert=kov+1;
        } else {
            p(3, n);
        }

        u(ert, n);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}