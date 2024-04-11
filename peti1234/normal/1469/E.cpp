#include <bits/stdc++.h>

using namespace std;
const int c=1050002;
int w, n, k, a, b, cnt;
vector<int> pos;
bool v[c];
string s;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> k >> s, cnt=0;
        a=max(0, k-20), b=k-a;
        for (int i=0; i<n; i++) {
            if (cnt>=a && i+b<=n) {
                int ert=0;
                for (int j=i; j<i+b; j++) {
                    ert*=2;
                    if (s[j]=='0') ert++;
                }
                v[ert]=1, pos.push_back(ert);
            }
            if (s[i]=='1') {
                cnt++;
            } else {
                cnt=0;
            }
        }
        int ans=c;
        for (int i=0; i<(1<<b); i++) {
            if (!v[i]) {
                ans=i;
                break;
            }
        }
        if (ans==c) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=0; i<a; i++) {
                cout << 0;
            }
            for (int j=1<<(b-1); j>=1; j/=2) {
                cout << (ans>=j);
                ans%=j;
            }
            cout << "\n";
        }
        for (int i:pos) {
            v[i]=0;
        }
        pos.clear();
    }
    return 0;
}