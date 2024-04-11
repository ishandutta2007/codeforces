#include <bits/stdc++.h>
using namespace std;

string strcat(string s, string temp) {
    for (int i = 0; i < temp.length(); i++)
        s.push_back(temp[i]);
    return s;
}

int main() {
    int n;
    cin >> n;

    map<string, int> count;
    vector<string> ans(n);

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (count.find(s) == count.end()) {
            count.insert({s, 0});
            ans[i] = "OK";
        }
        else {
            count[s] += 1;
            ans[i] = strcat(s, to_string(count[s]));
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}