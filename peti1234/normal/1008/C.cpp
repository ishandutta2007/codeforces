#include <bits/stdc++.h>

using namespace std;
int t[100001];
int n;
int b=1;
int k=1;
int c;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort (t+1, t+n+1);
    while(k<=n) {
        if (t[k]<=t[b]) {
            if (k==n) {
                break;
            }
        k++;
        } else {
            c++;
            k++;
            b++;
        }
    }
    cout << c << endl;
    return 0;
}