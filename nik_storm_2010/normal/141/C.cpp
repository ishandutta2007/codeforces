#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
const int N = 3000 + 10;

pair <int, string> a[N];
int b[N], n;
bool used[N];

int find(int x) {
    int ans;
    for (int i = n; i > 0; i--) {
        if (used[i] == false) x--;
        if (x == 0) {
            used[i] = true;
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].second >> a[i].first;
    sort(a + 1, a + n + 1);
    for (int i = n; i > 0; i--) {
        if (a[i].first > i - 1) { cout << -1; return 0; }
        b[i] = find(a[i].first + 1);
    }
    for (int i = 1; i <= n; i++) cout << a[i].second << " " << b[i] << endl;
    return 0;
}