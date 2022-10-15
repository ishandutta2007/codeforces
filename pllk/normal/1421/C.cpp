#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    cout << "4\n";
    cout << "R 2\n";
    n += n-2;
    cout << "L 2\n";
    n += 1;
    cout << "R 2\n";
    n += n-2;
    cout << "R " << (n-1) << "\n";
}