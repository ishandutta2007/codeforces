#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        string s, s2;
        cin >> s;
        s2=s;
        reverse(s2.begin(), s2.end());
        int n=s.size();
        if (n%2) {
            cout << "Bob\n";
        } else {
            int db=0, jo=1;
            while (s.size()>0 && s.back()==s2.back()) s.pop_back(), s2.pop_back(), db++;
            for (int i=db; i+db<n; i+=2) {
                if (s[i]!=s[i+1]) jo=0;
            }
            cout << (jo ? "Draw" : "Alice") << "\n";
        }
    }
    return 0;
}