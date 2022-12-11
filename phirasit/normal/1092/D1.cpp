#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& val : a) cin >> val;

    stack<int> stk;
    for (int& val : a) {
        val %= 2;

        if (!stk.empty() && stk.top() == val) {
            stk.pop();
        } else {
            stk.push(val);
        }
    }

    cout << (stk.size() <= 1 ? "YES" : "NO") << endl;

    return 0;
}