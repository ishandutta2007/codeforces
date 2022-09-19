#include <bits/stdc++.h>

using namespace std;
int ans=1, p=10, db;
string s;
bool v[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        char c=s[i];
        int x=c-'A';
        if (x>=0 && x<=9) {
            if (!v[x]) {
                v[x]=true;
                if (!i) ans*=p-1;
                else ans*=p;
                p--;
            }
        }
        if (c=='?') {
            if (!i) ans*=9;
            else db++;
        }
    }
    cout << ans;
    for (int i=1; i<=db; i++) cout << 0;
    cout << "\n";

    return 0;
}