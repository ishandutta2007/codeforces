#include <iostream>

using namespace std;

int t[3][3];

int main() {
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        cin >> t[i][j];
    int n = (2*t[0][1]+t[0][2]+t[2][0]+2*t[2][1])/2;
    t[0][0] = n-t[0][1]-t[0][2];
    t[1][1] = n-t[0][1]-t[2][1];
    t[2][2] = n-t[2][0]-t[2][1];
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        cout << t[i][j] << ((j == 2) ? "\n" : " ");
}