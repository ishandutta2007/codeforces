#include <bits/stdc++.h>

using namespace std;
const int c=1000002, cc=21;
#define rep() for (int i=0; i<n; i++)
int n, a[c], b[c], maxi[2*c][cc], ans, ut=-1, pos, lp=1, f, g;
string s;
int main()
{
    cin >> n >> s;
    rep() if (s[i]=='0') {
        for (int j=ut+1; j<=i; j++) a[j]=i;
        ut=i;
    }
    for(int i=ut+1; i<n; i++) a[i]=n;
    ut=-1;
    rep() if (s[i]=='1') {
        for (int j=ut+1; j<=i; j++) b[j]=i;
        ut=i;
    }
    for (int i=ut+1; i<n; i++) b[i]=n;
    rep() maxi[i][0]=max(a[i], b[i])-i;
    for (int j=1; j<cc; j++) rep() maxi[i][j]=max(maxi[i][j-1], maxi[i+(1<<(j-1))][j-1]);
    rep() {
        if (i==lp) lp*=2, f++;
        pos=0, g=f, ans=0;
        while(pos<n) {
            if (maxi[pos][g]<=i) pos+=(1<<g);
            else {
                while(g>=0) {
                    if (maxi[pos][g]<=i) pos+=(1<<g);
                    g--;
                }
                pos+=i+1, g=f, ans++;
            }
        }
        cout << ans << " ";
    }
    return 0;
}