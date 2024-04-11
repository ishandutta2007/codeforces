#include <bits/stdc++.h>

using namespace std;
int w, n, p;
string s, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, mini=s, p=1;
        for (int i=1; i<=n; i++) {
            string k;
            for (int j=i; j<n; j++) {
                k+=s[j];
            }
            if ((n-i)%2) {
                for (int j=i-1; j>=0; j--) {
                    k+=s[j];
                }
            } else {
                for (int j=0; j<i; j++) {
                    k+=s[j];
                }
            }
            if (k<mini) mini=k, p=i+1;
        }
        cout << mini << "\n" << p << "\n";
    }
    return 0;
}