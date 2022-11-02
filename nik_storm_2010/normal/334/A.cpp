#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int l = 1, r = n * n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / 2; j++) {
            cout << l << " ";
            l++;
        }
        for (int j = 1; j <= n / 2; j++) {
            cout << r << " ";
            r--;
        }
        cout << endl;
    }
    return 0;
}