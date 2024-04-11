#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int a = 1111111111, b = -1, c;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < a) a = v[i];
        if (v[i] > b) b = v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] > a && v[i] < b) c++;
    }
    cout << c << "\n";
}