#include <iostream>

using namespace std;

int t[3][3];

int main() {
    int n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t[i][j] += 1;
            cin >> n;
            t[i][j] += n;
            if (j > 0) t[i][j-1] += n;
            if (j < 2) t[i][j+1] += n;
            if (i > 0) t[i-1][j] += n;
            if (i < 2) t[i+1][j] += n;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (t[i][j]%2);            
        }
        cout << endl;
    }
}