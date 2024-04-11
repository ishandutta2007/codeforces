#include <iostream>

using namespace std;
const int mas[16] = {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};

int main() {
    int n;
    cin >> n;
    cout << mas[n - 1] << "\n";
    return 0;
}