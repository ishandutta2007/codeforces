#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &a) {
    stack<int> stk;
    for (int& val : a) {

        if (!stk.empty() && stk.top() == val) {
            stk.pop();
        } else if (stk.empty() || stk.top() > val) {
            stk.push(val);
        } else {
            return false;
        }
    }

    return stk.size() <= 1;
}
int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int& val : a) cin >> val;

    for (int i = 0; i < n; ++i) b[i] = a[n-i-1];

    cout << (check(a) && check(b) ? "YES" : "NO") << endl;

    return 0;
}