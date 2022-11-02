#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void check(int temp) {
    for (int i = temp / 7; i >= 0; --i)
        if ((temp - i * 7) % 3 == 0) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        check(temp);
    }
    //system("pause");
    return 0;
}