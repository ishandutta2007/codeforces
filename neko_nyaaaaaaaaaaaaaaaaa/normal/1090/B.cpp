#include <bits/stdc++.h>

using namespace std;

string text;
map<string, int> realIdx;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> biblios;
    string t;
    while (getline(cin, t)) {
        if (t == "\\begin{thebibliography}{99}") {
            break;
        }
        text.append(t);
        text.push_back('\n');
    }
    while (getline(cin, t)) {
        biblios.push_back(t);
    }
    // string mode = "none";
    int lastIdx = 0;
    vector<string> refs;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '{') {
            lastIdx = i + 1;
        } else if (text[i] == '}') {
            refs.push_back(text.substr(lastIdx, i - lastIdx));
        }
    }
    vector<pair<string, string>> brefs;
    for (int j = 0; j < biblios.size(); j++) {
        string s = biblios[j];
        int lastIdx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                lastIdx = i + 1;
            } else if (s[i] == '}') {
                brefs.push_back({s.substr(lastIdx, i - lastIdx), s});
            }
        }
    }
    brefs.pop_back();
    bool good = true;
    // vector<int> realIdx(refs.size());
    for (int i = 0; i < refs.size(); i++) {
        realIdx[refs[i]] = i;
        if (refs[i] != brefs[i].first) {
            good = false;
        }
    }
    if (good) {
        cout << "Correct" << endl;
        return 0;
    } else {
        cout << "Incorrect" << endl;
        cout << "\\begin{thebibliography}{99}" << endl;
        sort(brefs.begin(), brefs.end(), [&](auto a, auto b) { return realIdx[a.first] < realIdx[b.first]; });
        for (auto i : brefs) {
            cout << i.second << endl;
        }
        cout << "\\end{thebibliography}" << endl;
    }
}