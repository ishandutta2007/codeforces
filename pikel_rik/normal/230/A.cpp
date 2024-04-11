#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (s > x[i]) {
            s += y[i];
            v[i] = 1;
        }
    }
    
    int m = *max_element(x.begin(), x.end());
    int flag = 0;
    
    while (1) { 
        if (s > m) {
            flag = 1;
            break;
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0 and s > x[i]) {
                s += y[i];
                v[i] = 1;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    
    if (flag == 1)
        cout << "YES";
    else
        cout << "NO";
}