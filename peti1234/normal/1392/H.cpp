#include<bits/stdc++.h>

using namespace std;
const int c=4e6+2, h=998244353;
long long n, m, s=1, t[c];
int main() {
    cin >> n >> m, t[1]=1;
    for (int i=2; i<=n+m; i++) {
        t[i]=(h-h/i)*t[h%i]%h;
        if (i<=n) s+=t[i];
    }
    cout << (n*t[m+1]+1)%h*(s%h*m%h+1)%h;
}