#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair <int, int> > mas;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        mas.push_back(make_pair(num, i));
    }
    sort(mas.begin(), mas.end());
    int min_rating = 0;
    int ans[n];
    for (int i = 0; i < (int) mas.size(); ++i) {
        mas[i].first = max(mas[i].first, min_rating);
        min_rating = mas[i].first + 1;
        ans[mas[i].second] = mas[i].first;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";   
    }

    return 0;
}