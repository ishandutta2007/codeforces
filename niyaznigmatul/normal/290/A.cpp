#include <iostream>
#include <vector>
#include <string>
using namespace std;


const string names[] = {
"Washington",
"Adams",
"Jefferson",
"Madison",
"Monroe",
"Adams",
"Jackson",
"Van Buren",
"Harrison",
"Tyler",
"Polk",
"Taylor",
"Fillmore",
"Pierce",
"Buchanan",
"Lincoln",
"Johnson",
"Grant",
"Hayes",
"Garfield",
"Arthur",
"Cleveland",
"Harrison",
"Cleveland",
"McKinley",
"Roosevelt",
"Taft",
"Wilson",
"Harding",
"Coolidge",
"Hoover",
"Roosevelt",
"Truman",
"Eisenhower",
"Kennedy",
"Johnson",
"Nixon",
"Ford",
"Carter",
"Reagan",
"Bush",
"Clinton",
"Bush",
"Obama",
};
int main() {
/*    vector<string> e;
    string s, name;
    while (cin >> s) {
        e.push_back(s);
    }
    string ans[12345];
    for (int i = 0; i < (int) e.size(); ) {
        int j = i + 1;
        while (j < (int) e.size() && (e[j][0] < '0' || e[j][0] > '9')) ++j;
        int x = 0;
        for (int k = 0; k < (int) e[i].size(); k++) {
            char c = e[i][k];
            if (c >= '0' && c <= '9') x = x * 10 + c - '0';
        }
        ans[x] = e[j - 1];
        i = j;
    }
    for (int i = 1; !ans[i].empty(); i++) cout << "\"" << ans[i] << "\",\n";
    return 0;*/
    int n;
    cin >> n;
    cout << names[n - 1] << "\n";
}