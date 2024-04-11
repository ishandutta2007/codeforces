#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> view(n, vector<int> (3, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> view[i][j];
        }
    }
    
    int c = 0, c1 = 0;
    
    for (int i = 0; i < n; i++) {
        c1 = 0;
        for (int j = 0; j < 3; j++) {
            if (view[i][j] == 1)
                c1 += 1;
        }
        if (c1 >= 2)
            c += 1;
    }
    cout << c;
}