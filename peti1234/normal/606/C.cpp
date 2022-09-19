#include <bits/stdc++.h>
 
using namespace std;
int n;
int t[100001];
int l, a;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        t[a]=i;
    }
    for (int i=2; i<=n; i++) {
        if (t[i]>t[i-1]) {
            a++;
            l=max(a, l);
        } else {
            a=0;
        }
    }
    cout << n-l-1 << endl;
    return 0;
}