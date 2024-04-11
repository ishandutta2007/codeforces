#include <bits/stdc++.h>

using namespace std;
long long n, x, y;
long long a, b;
long long t[112], s[112], ans[112];
void add(long long a) {
    cout.flush() << "+ " << a << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t[n] >> s[n];
    for (long long i=n-1; i>=3; i--) {
        add(i), cin >> t[i] >> s[i];
    }
    add(1), add(2), add(1);
    cin >> t[0] >> s[0] >> t[2] >> s[2] >> t[1] >> s[1];
    x=t[1]-t[2], y=s[1]-s[2];
    ans[1]=sqrt(2*x)+1;
    ans[3]=y-s[0]+s[3]-1;
    ans[2]=y/(ans[3]+1)-1;
    for (int i=2; i<=n-2; i++) {
        x=s[i]-s[i+1];
        if (i==2) x=s[2]-s[0];
        x-=ans[i-2]*ans[i-1]+ans[i-1]*(ans[i+1]+1);
        x/=ans[i+1]+1;
        ans[i+2]=x-1;
        if (i==2) ans[1]--;
    }
    ans[n]++;
    cout << "! ";
    for (long long i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}
/*
5 1 6
1 15
4 20
5 24
5 40
8 48
*/