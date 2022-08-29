#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A) {
        cin >> a;
        a--;
    }

    int page = 0, days = 0;

    while (page < N) {
        int get_past = A[page];

        while (page < get_past)
            get_past = max(get_past, A[++page]);

        page++;
        days++;
    }

    cout << days << '\n';
}