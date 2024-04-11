#include <bits/stdc++.h>

using namespace std;
vector<int> kmp(string s) {
    int n=s.size();
    vector<int> pi(n, 0);
    for (int i=1; i<n; i++) {
        int h=pi[i-1];
        while (h>0 && s[i]!=s[h]) {
            h=pi[h-1];
        }
        if (s[i]==s[h]) {
            h++;
        }
        pi[i]=h;
    }
    return pi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        string s2=s;
        reverse(s2.begin(), s2.end());

        if (s==s2) {
            cout << s << "\n";
            continue;
        }

        int pos=0, n=s.size();
        while (s[pos]==s[n-1-pos]) {
            pos++;
        }

        string p1=s.substr(pos, n-2*pos), p2=p1;
        reverse(p2.begin(), p2.end());
        string x1=p1+"#"+p2, x2=p2+"#"+p1;

        vector<int> pi1=kmp(x1), pi2=kmp(x2);
        int v1=pi1.back(), v2=pi2.back();

        string valasz=s.substr(0, pos);
        if (v1>v2) {
            valasz+=s.substr(pos, v1);
        } else {
            valasz+=s.substr(n-pos-v2, v2);
        }
        valasz+=s.substr(n-pos, pos);
        cout << valasz << "\n";
    }
    return 0;
}