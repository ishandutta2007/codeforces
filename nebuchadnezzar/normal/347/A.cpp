#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector <int> mas;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        mas.push_back(num);
    }
    sort(mas.begin(), mas.end());

    cout << mas[mas.size() - 1] << " ";

    for (int i = 1; i < n - 1; ++i) {
        cout << mas[i] << " ";
    }

    cout << mas[0];

    return 0;
}