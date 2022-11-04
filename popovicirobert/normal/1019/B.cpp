#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

bool vis[MAXN + 1];
int arr[MAXN + 1];

inline int ask(int x) {
    if(vis[x])
        return arr[x];
    vis[x] = 1;
    cout << "?" << " " << x << "\n";
    int ans;
    cin >> ans;
    return arr[x] = ans;
}

int n;

inline int get(int x) {
    int ans = ask(x) - ask(x + n / 2);
    if(ans == 0) {
        cout << "! " << x << "\n";
        exit(0);
    }
    return ans;
}

inline bool sign(int x) {
    if(x < 0)
        return 0;
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int n;
    ios::sync_with_stdio(false);
    cin >> n;
    if(abs(get(1)) % 2) {
        cout << "! -1\n";
        return 0;
    }
    int l = 1, r = n / 2;
    while(r - l >= 2) {
        int mid = (l + r) / 2;
        int a = get(l), b = get(mid), c = get(r);
        if(sign(a) == sign(b)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << "! -1\n";
    //cin.close();
    //cout.close();
    return 0;
}