#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h1, a1, c1;
    cin >> h1 >> a1 >> c1;
    int h2, a2;
    cin >> h2 >> a2;
    vector<string> ans;
    while (h2 > 0) {
        if (h1 > a2 || h2 <= a1) {
            ans.push_back("STRIKE");
            h2 -= a1;
        } else {
            ans.push_back("HEAL");
            h1 += c1;
        }
        h1 -= a2;
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << '\n';
    //system("pause");
    return 0;
}