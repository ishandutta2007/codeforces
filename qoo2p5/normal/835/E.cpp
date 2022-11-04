#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int ask(const vector<int> &a) {
    if (a.empty()) {
        return 0;
    }
    cout << "? ";
    cout << a.size() << " ";
    for (int el : a) {
        cout << el << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int solve(const vector<int> &a) {
    int left = 0;
    int right = (int) a.size();
    
    while (right - left > 1) {
        int mid = (left + right) / 2;
        
        vector<int> b;
        for (int i = left; i < mid; i++) {
            b.push_back(a[i]);
        }
        
        int cur = ask(b);
        if (cur == y || cur == (x ^ y)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return a[left];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> x >> y;
    
    int diff = 0;
    int diff_bit = -1;
    
    for (int bit = 0; bit <= 9; bit++) {
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            if (i & (1 << bit)) {
                a.push_back(i);
            }
        }
        
        int cur = ask(a);
        if (cur == y || cur == (x ^ y)) {
            diff |= (1 << bit);
            diff_bit = bit;
        }
    }
    
    assert(diff > 0 && diff_bit != -1);
    
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (i & (1 << diff_bit)) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    
    if (a.size() > b.size()) {
        swap(a, b);
    }
    
    int pos1 = solve(a);
    int pos2 = pos1 ^ diff;
    if (pos1 > pos2) {
        swap(pos1, pos2);
    }
    cout << "! " << pos1 << " " << pos2 << endl;
    
    return 0;
}