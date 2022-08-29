#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<int, int> best_income;

void read() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;
        best_income[a] = max(best_income[a], x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    read();

    long long total = 0;

    for (map<int, int>::iterator it = best_income.begin(); it != best_income.end(); it++) {
        total += it->second;
    }

    cout << total << '\n';
    return 0;
}