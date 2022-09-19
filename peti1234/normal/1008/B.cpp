#include <bits/stdc++.h>

using namespace std;
int n;
int f=INT_MAX;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        if (a<b) {
            swap(a, b);
        }
            if (b>f) {
                cout << "NO" << endl;
                return 0;
            }
            if (a<=f) {
                f=a;
            } else {
                f=b;
            }
    }
    cout << "YES";
    return 0;
}