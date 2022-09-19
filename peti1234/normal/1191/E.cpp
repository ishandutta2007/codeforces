#include <bits/stdc++.h>

using namespace std;
int n, k;
bool v[100002];
int a, b, c, d;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    for (int i=1; i<=n; i++) {
        if (s[i-1]=='1') {
            v[i]=true;
        }
        if (v[i]) {
            if (a==0) {
                a=i;
            } else {
                b=i;
            }
        } else {
            if (c==0) {
                c=i;
            } else {
                d=i;
            }
        }
    }

    if (k>b-a || k>d-c) {
        cout << "tokitsukaze" << endl;
        return 0;
    }
    if (b-a==k && d-c==k && d>a && b>c) {
        cout << "quailty" << endl;
        return 0;
    }
    cout << "once again" << endl;
    return 0;
}