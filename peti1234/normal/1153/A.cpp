#include <bits/stdc++.h>

using namespace std;
int n, t;
int res=INT_MAX;
int x=0;
int main()
{
    cin >> n >> t;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        while(a<t) {
            a+=b;
        }
        if (a-t<res) {
            x=i;
            res=a-t;
        }
    }
    cout << x << endl;
    return 0;
}