#include <bits/stdc++.h>

using namespace std;
int n;
int t[1001];
int mini=0, sum=INT_MAX;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=100; i++) {
        int x=0;
        for (int j=1; j<=n; j++) {
            x+=max(0, abs(t[j]-i)-1);
        }
        if (x<=sum) {
            sum=x;
            mini=i;
        }
    }
    cout << mini <<  " " << sum << endl;
    return 0;
}