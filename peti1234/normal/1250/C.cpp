#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, cs, a, b, mini, ert, t[c], v[c], r[c], db, x, y, kezd, cnt, ans;
string s;
int main()
{
    cin >> n;
    cin >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') v[i]=1;
        else v[i]=-1;
        ert+=v[i];
        if (ert<mini) mini=ert, cs=i+1;
    }
    for (int i=0; i<n; i++) r[(i+n-cs)%n]=v[i];
    t[0]=r[0];
    for (int i=1; i<n; i++) t[i]=t[i-1]+r[i], db+=!t[i];
    if (t[n-1]!=0) {
        cout << 0 << "\n" << 1 << " " << 1 << "\n";
        return 0;
    }
    ans=db;
    for (int i=0; i<n; i++) {
        if (t[i]<2) kezd=i+1, cnt=0;
        if (t[i]==2) {
            cnt++;
            if (cnt+db>ans) ans=cnt+db, x=kezd, y=i+1;
        }
    }
    kezd=0, cnt=0;
    for (int i=0; i<n; i++) {
        if (t[i]<1) kezd=i+1, cnt=0;
        if (t[i]==1) {
            cnt++;
            if (cnt>ans) ans=cnt, x=kezd, y=i+1;
        }
    }
    cout << ans << "\n" << (x+cs)%n+1 << " " << (y+cs)%n+1 << "\n";
    return 0;
}