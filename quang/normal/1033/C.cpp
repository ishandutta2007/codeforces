#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MAGIC = 350;

int n;
int a[N];
int pos[N];
bool result[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }  
    for (int i = n; i > 0; i--) {
        int id = pos[i];
        bool win = 0;
        for (int j = id + i; j <= n; j += i) {
            win |= (result[j] == 0 && a[j] > i);
        }
        for (int j = id - i; j > 0; j -= i) {
            win |= (result[j] == 0 && a[j] > i);
        }
        result[id] = win;
    }
    for (int i = 1; i <= n; i++) {
        cout << (result[i] ? 'A' : 'B');
    }
    cout << endl;
    return 0;
}