#include <bits/stdc++.h>

using namespace std;
const int c=100002;
string s;
int n, z[c], db[c], cnt=1;
int main()
{
    cin >> s, n=s.size();
    z[0]=n, db[n]++;
    for (int i=1, l=0, r=0; i<n; i++) {
        if (i<=r) z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
        db[z[i]]++;
        if (i+z[i]==n) cnt++;
    }
    for (int i=n-1; i; i--) db[i]+=db[i+1];
    cout << cnt << "\n";
    for (int i=n-1; i>=0; i--) if (i+z[i]==n) cout << z[i] << " " << db[z[i]] << "\n";
    return 0;
}