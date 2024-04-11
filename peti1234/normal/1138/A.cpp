#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int l=0, j=1, maxi;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        s+=x;
    }
    s+=3;
    for (int i=1; i<s.size(); i++) {
        if (s[i]==s[i-1]) {
            j++;
        } else {
            maxi=max(maxi, min(l, j));
            l=j;
            j=1;
        }
    }
    cout << maxi*2 << "\n";
    return 0;
}