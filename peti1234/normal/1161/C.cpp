#include <bits/stdc++.h>

using namespace std;
int n;
int mini=INT_MAX;
int cnt;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x<mini) {
            cnt=0;
        }
        mini=min(mini, x);
        if (x==mini) {
            cnt++;
        }
    }
    if (cnt>n/2) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
    return 0;
}