#include <bits/stdc++.h>

using namespace std;
int n, k;
long long fakt[5005][5005], mod=998244353, ans;
string s;
int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            fakt[i][j]=(j==0 ? 1 : (fakt[i-1][j]+fakt[i-1][j-1])%mod);
        }
    }
    int cnt=0;
    for (int i=0; i<n; i++) {
        cnt+=(s[i]=='1');
    }
    if (cnt<k) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i=0; i<n; i++) {
        int pos=i, db=s[i]=='1';
        while (pos+1<n && db<=k) pos++, db+=(s[pos]=='1');
        if (db>k) pos--, db--;
        int len=pos-i+1;
        if (len>db && db>0) {
            ans=(ans+fakt[len-1][db-(s[i]=='0')])%mod;
        }
    }
    cout << (ans+1)%mod << "\n";
    return 0;
}