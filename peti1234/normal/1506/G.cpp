#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, kul[c];
string s;
set<char> k;
void solve(string s) {
    //cout << "kerdes " << s << "\n";
    n=s.size();
    if (!n) {
        return;
    }
    kul[n]=0;
    k.clear();
    for (int i=n-1; i>=0; i--) {
        kul[i]=kul[i+1];
        if (k.find(s[i])==k.end()) {
            kul[i]++;
            k.insert(s[i]);
        }
    }
    int pos=0;
    for (int i=1; i<n; i++) {
        if (kul[i]==kul[pos] && s[i]>s[pos]) {
            pos=i;
        }
    }
    //cout << "valasz: ";
    cout << s[pos];
    //cout << "\n";
    string ss;
    for (int i=pos; i<n; i++) {
        if (s[i]!=s[pos]) {
            ss+=s[i];
        }
    }
    solve(ss);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        solve(s);
        cout << "\n";
    }
    return 0;
}