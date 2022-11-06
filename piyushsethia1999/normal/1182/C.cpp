#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

bool isv(char c) {
    return (c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u');
}

std::vector<char> cp = {'a', 'e', 'i', 'o', 'u'};

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    std::vector<int> cnt(n, 0);
    std::vector<char> las(n);
    string str[n + 1];
    std::map<pair<int, char>, int> m;
    std::map<int, std::vector<int> > mm;
    std::vector<std::vector<int> > ad(1000005);
    std::vector<pair<int, int> > v;
    set<int> ss;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s; str[i + 1] = s;
        for (int j = 0; j < s.size(); ++j) {
            if (isv(s[j])) {
                cnt[i]++;
                las[i] = s[j];
            }
        }
        if (m[{cnt[i], las[i]}] == 0) {
            m[{cnt[i], las[i]}] = i + 1;
        } else {
            v.pb(m[{cnt[i], las[i]}], i + 1);
            m[{cnt[i], las[i]}] = 0;
        }
        ss.insert(cnt[i]);
    }
    int to = 0;
    std::vector<pair<pair<int, int>, pair<int, int> > > ans;
    for (int cn : ss) {
        std::vector<int> vv;
        for (char c : cp)
            if (m[{cn, c}])
                vv.pb(m[{cn, c}]);
        while (vv.size() >= 2 && (!v.empty())) {
            int y = vv.back();
            vv.pop_back();
            int x = vv.back();
            vv.pop_back();
            ans.push_back({{x, y}, v.back()});
            v.pop_back();
        } 
    }
    int siz = v.size();
    while (siz >= 2) {
        auto y = v.back();
        v.pop_back();
        auto x = v.back();
        v.pop_back();
        ans.push_back({y, x});
        siz -= 2;
    }
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << str[p.first.first] + " " +
                str[p.second.first] + "\n" +
                str[p.first.second] + " " +
                str[p.second.second] + "\n";
    } 
}