#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

string ask(int x, int y) {
    cout << x << " " << y << endl;
    cout.flush();
    string foo;
    cin >> foo;
    return foo;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        ask(0, 0);
        cout << 0 << " " << 1 << " " << 1 << " " << 0 << endl;
        cout.flush();
        return 0;
    }
    string a = ask(0, INF);
    string b = ask(INF, INF);
    if (a == b) {
        int high = INF;
        int low = 0;
        for (int i = 3; i <= n; i++) {
            int mid = (1ll * low + high) >> 1ll;
            string foo = ask(INF, mid);
            if (foo == b) {
                high = mid;
            } else {
                low = mid;
            }
        }
        assert(low + 1 < high);
        cout << 0 << " " << 0 << " " << INF << " " << low + 1 << endl;
        cout.flush();
    } else {
        int low = 0;
        int high = INF;
        for (int i = 3; i <= n; i++) {
            int mid = (1ll * low + high) >> 1ll;
            string foo = ask(mid, INF);
            if (foo == a) {
                low = mid;
            } else {
                high = mid;
            }
        }
        assert(low + 1 < high);
        cout << 0 << " " << 0 << " " << low + 1 <<  " " << INF << endl;
        cout.flush();
    }
    return 0;
}