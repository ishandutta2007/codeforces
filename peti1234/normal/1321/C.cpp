#include <bits/stdc++.h>

using namespace std;
int n, cnt;
string s;
int main()
{
    cin >> n >> s;
    for (char ert='z'; ert>='a'; ert--) {
        n=s.size();
        string s2;
        for (int i=0; i<n; i++) {
            int pos=i, pos2=i;
            while (pos>=0 && s[pos]==s[i]) {
                pos--;
            }
            while (pos2<n && s[pos2]==s[i]) {
                pos2++;
            }
            if (s[i]==ert && ((pos>=0 && s[pos]==s[i]-1) || (pos2<n && s[pos2]==s[i]-1))) {
                cnt++;
            } else {
                s2+=s[i];
            }
        }
        s=s2;
    }
    cout << cnt << "\n";
    return 0;
}
/*
2
ab
*/