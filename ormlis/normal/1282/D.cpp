#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <map>
#include <bitset>
#include <iomanip>
 
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
 
typedef long long ll;
using namespace std;
 
const int Nm = 200001;
 
int types[Nm];
 
char s[300];
 
int req(int n) {
    range(i, n) {
        cout << s[i];
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}
 
void solve() {
    int a, b;
    range(i, 300) {
        cout << 'a';
    }
    cout << endl;
    cin >> a;
    if(a == 0) exit(0);
    a = 300 - a;
    range(i, 300) {
        cout << 'b';
    }
    cout << endl;
    cin >> b;
    if(b == 0) exit(0);
    b = 300 - b;
    int n = a + b;
    range(i, n) {
        s[i] = 'a';
    }
    int ans = b;
    int ans1;
    range(i, n - 1) {
        s[i] = 'b';
        ans1 = req(n);
        if (ans1 > ans) {
            s[i] = 'a';
        } else {
            ans = ans1;
        }
    }
    if(ans) {
        s[n - 1] = 'b';
    }
    req(n);
}
 
 
int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}