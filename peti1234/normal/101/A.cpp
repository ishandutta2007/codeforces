#include <bits/stdc++.h>

using namespace std;
int n, k, cnt=26, db[26], h[26];
string s;
vector<pair<int, int> > sz;
int main()
{
    cin >> s >> k;
    n=s.size();
    for (int i=0; i<n; i++) {
        int x=s[i]-'a';
        db[x]++;
    }
    for (int i=0; i<26; i++) {
        sz.push_back({db[i], i});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        if (x.first<=k) {
            k-=x.first;
            cnt--;
            h[x.second]=1;
        }
    }
    cout << cnt << "\n";
    for (int i=0; i<n; i++) {
        int x=s[i]-'a';
        if (!h[x]) {
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}