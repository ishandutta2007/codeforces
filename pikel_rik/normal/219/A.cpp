#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    vector<int> count(26);
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 97] += 1;
    }

    int flag = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] % k != 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        cout << "-1";
    else {
        string temp;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i] / k; j++) {
                temp.push_back((char)(i + 97));
            }
        }
        for (int i = 0; i < k; i++) {
            cout << temp;
        }
    }
    return 0;
}