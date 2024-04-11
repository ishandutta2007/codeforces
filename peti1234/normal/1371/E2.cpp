#include <bits/stdc++.h>

using namespace std;
int n, k, x, y, a, t[100002], sok=1e9;
int pr(int a) {
    int e=0, f=0, p=0;
    for (int i=a; i<a+n; i++) {
        while(p<n && i>=t[p]) p++;
        if (p<=i-a) e=1;
        if (p-i+a>=k) f=1;
    }
    if (e) return -1;
    return f;
}
int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> t[i];
    sort(t, t+n);
    y=sok;
    while (y-x>1) {
        int z=(x+y)/2;
        if (pr(z)==-1) x=z;
        else y=z;
    }
    a=y, x=0, y=sok;
    while (y-x>1) {
        int z=(x+y)/2;
        if (pr(z)==1) y=z;
        else x=z;
    }
    cout << y-a << "\n";
    for (int i=a; i<y; i++) cout << i << " ";
    return 0;
}