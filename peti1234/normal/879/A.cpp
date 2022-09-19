#include <bits/stdc++.h>

using namespace std;
int n;
int k;
int main()
{
    cin >> n;
    for (int i=1; i<=n;i++) {
        int a, b;
        cin >> a >> b;
        while (a<=k) {
            a+=b;
        }
        k=a;
    }
    cout << k << endl;
    return 0;
}