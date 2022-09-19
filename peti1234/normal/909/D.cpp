#include <bits/stdc++.h>

using namespace std;
string s;
vector<pair<char, int> > regi, uj;
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (i==0 || s[i]!=s[i-1]) {
            regi.push_back({s[i], 1});
        } else {
            regi.back().second++;
        }
    }
    while (regi.size()>1) {
        ans++;
        int si=regi.size();
        for (int i=0; i<si; i++) {
            char fi=regi[i].first;
            int kul=0, se=regi[i].second;
            if (i>0) kul++;
            if (i<si-1) kul++;
            se=max(0, se-kul);
            if (se>0) {
                if (uj.size()>0 && fi==uj.back().first) {
                    uj.back().second+=se;
                } else {
                    uj.push_back({fi, se});
                }
            }
        }
        regi=uj;
        uj.clear();
    }
    cout << ans << "\n";
    return 0;
}