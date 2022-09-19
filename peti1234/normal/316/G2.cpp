#include <bits/stdc++.h>

using namespace std;
const int c=500002;
string s, k[11], r;
int n, f, kis[11], nagy[11], kom[c], z[2*c], ans;
bool jo[c];
void zz(string s) {
    int n = (int) s.length();
    for (int i=0; i<=n; i++) {
        z[i]=0;
    }
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int main()
{
    cin >> s, f=s.size();
    cin >> n;
    k[0]=s;
    for (int i=1; i<=n; i++) {
        cin >> k[i] >> kis[i] >> nagy[i];
    }
    for (int i=0; i<f; i++) {
        int ff=f-i;
        for (int i=1; i<=ff; i++) {
            jo[i]=1;
        }
        for (int j=0; j<=n; j++) {
            r=s.substr(i, f-i)+'#'+k[j];
            //cout << r << endl;
            zz(r);
            int si=r.size();
            for (int i=0; i<=ff+1; i++) {
                kom[i]=0;
            }
            int sp=si;
            if (j==0) {
                sp=f+1;
            }
            for (int j=f-i; j<sp; j++) {
                kom[z[j]]++;
            }
            for (int jj=ff; jj>0; jj--) {
                kom[jj]+=kom[jj+1];
                if (kom[jj]<kis[j] || kom[jj]>nagy[j]) {
                    jo[jj]=0;
                }
            }
        }
        for (int j=1; j<=ff; j++) {
            if (jo[j]) {
                ans++;
            }
        }
        //cout << "vege " << i << " " << ans << endl;
    }
    cout << ans << "\n";
    return 0;
}
/*
aab
0
*/