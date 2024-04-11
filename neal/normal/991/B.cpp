#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool average5(vector<int> grades) {
    int n = grades.size();
    int sum = accumulate(grades.begin(), grades.end(), 0);
    return 2 * sum >= 9 * n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> grades(n);

    for (int i = 0; i < n; i++)
        cin >> grades[i];

    sort(grades.begin(), grades.end());
    int count = 0;

    while (count < n && !average5(grades)) {
        grades[count++] = 5;
    }

    cout << count << '\n';
    return 0;
}