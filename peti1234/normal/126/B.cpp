#include <bits/stdc++.h>

using namespace std;
string s;
vector<int> pi;
int maxi, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    pi.resize(n);
    for (int i=1; i<n; i++) {
        int h=pi[i-1];
        while (h>0 && s[i]!=s[h]) {
            h=pi[h-1];
        }
        if (s[i]==s[h]) {
            h++;
        }
        pi[i]=h;
        if (i<n-1) {
            maxi=max(maxi, pi[i]);
        }
    }
    int ut=pi[n-1];
    while (ut) {
        if (ut<=maxi) {
            cout << s.substr(0, ut) << "\n";
            return 0;
        }
        ut=pi[ut-1];
    }
    cout << "Just a legend\n";
    return 0;
}