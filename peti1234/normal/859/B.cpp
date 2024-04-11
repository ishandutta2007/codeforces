#include <bits/stdc++.h>

using namespace std;
int n;
int mini=INT_MAX;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a=n/i;
        a+=n%i!=0;
        mini=min(mini, i+a);
    }
    cout << mini*2 << endl;
    return 0;
}