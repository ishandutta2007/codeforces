#include <bits/stdc++.h>

using namespace std;
int a, b, c, e, n;
vector <int> t;
int k;

int main()
{
    e=1;
    cin >> n;
    k=2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t.push_back(x);
    }
    sort (t.begin(), t.end());
    for (int i=1; i<t.size(); i++) {

         if (t[i]!=t[i-1]) {
            e++;
                }
            }
    if (e>=4) {
        cout << "NO" << endl;
        return 0;
    }

    if (e<=2) {
        cout << "YES" << endl;
        return 0;
    }
    a=t[0], c=t.back();
    for (int i=1; i<t.size(); i++) {
        if (a!=t[i] && c!=t[i]) {
            b=t[i];
        }
    }
    if (a+c==2*b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}