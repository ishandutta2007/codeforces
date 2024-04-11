#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], bal, jobb, ut;
string ans;
void ba() {
    ans+="L";
    ut=t[bal++];
}
void ja() {
    ans+="R";
    ut=t[jobb--];
}
int main()
{
    cin >> n;
    bal=1, jobb=n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    while (bal<=jobb) {
        if (max(t[bal], t[jobb])>ut) {
            if (t[jobb]<=ut || t[bal]>ut && t[bal]<t[jobb]) {
                ba();
            } else if (t[bal]<=ut || t[jobb]>ut && t[jobb]<t[bal]) {
                ja();
            } else if (t[bal]==t[jobb]) {
                int c1=0, c2=0;
                while (bal+c1+1<=n && t[bal+c1+1]>t[bal+c1]) {
                    c1++;
                }
                while (jobb-c2-1>=1 && t[jobb-c2-1]>t[jobb-c2]) {
                    c2++;
                }
                if (c1>c2) {
                    ba();
                } else {
                    ja();
                }
            }
        } else {
            break;
        }
    }
    cout << ans.size() << "\n" << ans << "\n";
    return 0;
}