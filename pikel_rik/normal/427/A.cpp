#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> s;

    for (int i = n-1; i >= 0; i--) {
        if (a[i] == -1)
            s.push(a[i]);
        else if (!s.empty())
            while (a[i]-- and !s.empty())
                s.pop();
    }

    cout << s.size();
    return 0;
}