#include <iostream>
#include <string>

using namespace std;
const int N = 1e5 + 100;

string a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    string last = "";
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (last < a[x]) last = a[x]; else
        if (last < b[x]) last = b[x]; else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}