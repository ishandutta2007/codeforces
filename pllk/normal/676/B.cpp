#include <iostream>

using namespace std;

int n, t;
double s[20][20];
int c;

int main() {
    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        s[0][0]++;
        c = 0;
        for (int j = 0; j < n; j++) {
            for (int h = 0; h <= j; h++) {
                if (s[j][h] < 1) continue;
                c++;
                double u = s[j][h]-1;
                s[j][h] = 1;
                s[j+1][h] += u/2;
                s[j+1][h+1] += u/2;
            }
        }
    }
    cout << c << "\n";
}