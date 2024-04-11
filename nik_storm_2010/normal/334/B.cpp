#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> a[8];

int main() {
    for (int i = 0; i < 8; i++) cin >> a[i].first >> a[i].second;
    sort(a, a+8);
    bool flag = true;
    if (a[0].first != a[1].first || a[1].first != a[2].first || a[3].first != a[4].first || a[5].first != a[6].first || a[6].first != a[7].first) flag = false;
    if (a[0].first == a[3].first || a[0].first == a[5].first || a[3].first == a[5].first) flag = false;
    if (a[0].second != a[3].second || a[3].second != a[5].second || a[1].second != a[6].second || a[2].second != a[4].second || a[4].second != a[7].second) flag = false;
    if (a[0].second == a[1].second || a[0].second == a[2].second || a[1].second == a[2].second) flag = false;
    if (flag) cout << "respectable"; else cout << "ugly";
    return 0;
}