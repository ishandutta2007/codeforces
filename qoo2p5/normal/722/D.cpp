#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

const int N = (int) 1e5 + 123;

int n;
int y[N];

set<int> x;
map<int, int> cnt;

bool check(int k) {
    x.clear();
    cnt.clear();
    
    for (int i = 0; i < n; i++) {
        int x = y[i];
        while (x > k) {
            x /= 2;
        }
        cnt[x]++;
    }
    
    for (auto &it : cnt) {
        int num = it.first;
        int c = it.second;
        
        int xx = num;
        int len = 0;
        while (xx > 0) {
            xx /= 2;
            len++;
        }
        
        for (int i = 0; i < len && c > 0; i++) {
            int to = num >> i;
            if (!x.count(to)) {
                x.insert(to);
                c--;
            }
        }
        
        if (c > 0) {
            return false;
        }
    }
    
    return true;
}

int run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    
    int left = 0;
    int right = INF;
    
    while (right - left > 1) {
        int mid = (left + right) / 2;
        
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    check(right);
    
    for (int el : x) {
        cout << el << " ";
    }
    cout << "\n";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}