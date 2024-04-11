#include <bits/stdc++.h>
using namespace std;

int count(vector<int> a, int n) {
    int c = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == n)
            c += 1;
    }
    return c;
}

int maxOnes(vector<int> a, int i, int j) {
    vector<int> temp;

    for (int i = 0; i < a.size(); i++) {
        temp.push_back(a[i]);
    }

    for (int k = i-1; k < j; k++) {
        temp[k] = 1 - temp[k];
    }
    return count(temp, 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    int m = 0, temp;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            temp = maxOnes(a, i, j);
            if (temp > m)
                m = temp;
        }
    }
    cout << m;
}