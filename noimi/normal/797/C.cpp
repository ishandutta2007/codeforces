#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<char> r(n + 1); // i 
    r[n] = char('z' + 1);  // 

    for(int i = n - 1; i >= 0; i--) r[i] = min(r[i + 1], s[i]);

    stack<char> v; // 
    for(int i = 0; i < n + 1; i++) {
        while(!empty(v) and r[i] >= v.top()) {
            // 
            cout << v.top();
            v.pop();
        }
        v.emplace(s[i]);
    }
    cout << endl;
}