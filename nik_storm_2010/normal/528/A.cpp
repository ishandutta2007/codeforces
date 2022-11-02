#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

set <int> hor, ver;
multiset <int> horall, verall;

int main() {
    ios_base::sync_with_stdio(false);
    int w, h, n;
    cin >> w >> h >> n;
    hor.insert(0);
    hor.insert(w);
    ver.insert(0);
    ver.insert(h);
    horall.insert(w);
    verall.insert(h);
    for (int i = 1; i <= n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'V') {
            set <int>::iterator it = hor.lower_bound(x);
            set <int>::iterator it2 = it;
            it2--;
            int n1 = x - *it2;
            int n2 = *it - x;
            horall.erase(horall.find(*it - *it2));
            horall.insert(n1);
            horall.insert(n2);
            hor.insert(x);
        } else {
            set <int>::iterator it = ver.lower_bound(x);
            set <int>::iterator it2 = it;
            it2--;
            int n1 = x - *it2;
            int n2 = *it - x;
            verall.erase(verall.find(*it - *it2));
            verall.insert(n1);
            verall.insert(n2);
            ver.insert(x);
        }
        set <int>::iterator it = horall.end();
        it--;
        set <int>::iterator it2 = verall.end();
        it2--;
        long long ans = 1LL * (*it) * (*it2);
        cout << ans << "\n";
    }
    return 0;
}