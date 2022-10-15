#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a, b;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i += 2) a.push_back(i);
    for (int i = 2; i <= n; i += 2) b.push_back(i);
    if (n%2 == 0) {
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
        for (int i = (int)a.size()-1; i >= 0; i--) cout << a[i] << " ";
        for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
        for (int i = (int)b.size()-2; i >= 0; i--) cout << b[i] << " ";
        cout << n << "\n";
    } else {
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
        for (int i = (int)a.size()-2; i >= 0; i--) cout << a[i] << " ";
        for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
        for (int i = (int)b.size()-1; i >= 0; i--) cout << b[i] << " ";
        cout << n << "\n";
    }
}