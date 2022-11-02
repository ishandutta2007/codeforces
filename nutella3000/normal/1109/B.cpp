#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> a;
    a.resize(26,0);
    for(int i = 0;i < s.size();i++) {
        a[s[i] - 'a']++;
    }
    bool nex = false;
    int ind = 0;
    int cnt = 0;
    for(int i = 0;i < 26;i++) {
        if (a[i] % 2 == 1) {
            nex = true; ind = i;
        }
        if (a[i] > 0) cnt++;
    }
    if ((nex && cnt == 2 && a[ind] == 1) || cnt == 1) cout << "Impossible";
    else{
        bool one = false;
        for(int i = 0;i < s.size();i++) {
            vector<char> a;
            for(int j = i + 1;j < s.size();j++) {
                a.push_back(s[j]);
            }
            for(int j = 0;j <= i;j++) a.push_back(s[j]);
            bool u =true;
            for(int j = 0;j < s.size();j++) if (a[j] != s[j]) u = false;
            if (u) continue;
            else u= true;
            for(int j = 0;j < a.size() / 2;j++) {
                if (a[j] != a[a.size() - j - 1]) u = false;
            }
            if (u) one = true;
        }
        if (one) cout << 1;
        else cout << 2;
    }
}