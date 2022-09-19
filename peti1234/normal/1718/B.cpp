#include <bits/stdc++.h>

using namespace std;
const int c=105;
long long fib[c], pref[c], n, t[c], sum;
bool solve() {
    cin >> n;
    sum=0;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    int pos=0;
    for (int i=1; i<=60; i++) {
        if (sum==pref[i]) {
            pos=i;
        }
    }
    if (n>pos) return false;
    int ut=0;
    for (int i=pos; i>=1; i--) {
        int x=0;
        for (int j=1; j<=n; j++) {
            if (j!=ut && t[j]>t[x]) {
                x=j;
            }
        }
        if (t[x]<fib[i]) return false;
        t[x]-=fib[i];
        ut=x;
    }
    return true;
}
int main()
{
    fib[1]=1, fib[2]=1;
    pref[1]=1, pref[2]=2;
    for (int i=3; i<=60; i++) {
        fib[i]=fib[i-1]+fib[i-2];
        pref[i]=pref[i-1]+fib[i];
    }
    int w;
    cin >> w;
    while (w--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
3
3 1 3
*/