#include <bits/stdc++.h>

using namespace std;
int n;
int t[11];
int main()
{
    cin >> n;
    for (int i=1; i<=10; i++) {
        t[i]=2;
    }
    for (int i=1; i<=n; i++) {
        char a;
        int b;
        cin >> a >> b;
        for (int i=10; i>=1; i--) {
            if (b%2==0 && a=='&') {
                t[i]=0;
            }
            if (b%2==1 && a=='|') {
                t[i]=1;
            }
            if (b%2==1 && a=='^') {
                if (t[i]%2==0) {
                    t[i]++;
                } else {
                t[i]--;
                }
            }
            b/=2;
        }
    }
    cout << 3 << endl;
    int sz=1023;
    int r=1;
    for (int i=10; i>=1; i--) {
        if (t[i]==0) {
            sz-=r;
        }
        r*=2;
    }
    cout << '&' << " " << sz << endl;
    sz=0;
    r=1;
    for (int i=10; i>=1; i--) {
        if (t[i]==1) {
            sz+=r;
        }
        r*=2;
    }
    cout << '|' << " " << sz << endl;
    sz=0;
    r=1;
    for (int i=10; i>=1; i--) {
        if (t[i]==3) {
            sz+=r;
        }
        r*=2;
    }
    cout << '^' << " " << sz << endl;
    return 0;
}