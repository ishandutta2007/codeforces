#include <bits/stdc++.h>

using namespace std;
int n, maxi;
string s;
int main()
{
    cin >> s;
    n=s.size();
    for (int pos=0; pos<n; pos++) {
        for (int i=0; i+pos<=n; i++) {
            for (int j=0; j+i<=n; j++) {
                if (j==pos) {
                    continue;
                }
                if (s.substr(j, i)==s.substr(pos, i)) {
                    maxi=max(maxi, i);
                }
            }
        }
    }
    cout << maxi << "\n";
    return 0;
}