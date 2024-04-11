#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int sum=0, e=0, n=0;
        for (int i=0; i<s.size(); i++) {
            char c=s[i];
            int x=c-'0';
            sum+=x;
            e+=(!(x%2));
            n+=(x==0);
        }
        if (!(sum%3) && n && e>=2) {
            cout << "red";
        } else {
            cout << "cyan";
        }
        cout << "\n";
    }
    return 0;
}