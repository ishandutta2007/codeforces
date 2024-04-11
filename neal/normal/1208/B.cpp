#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    map<int, int> freq;
    int duplicates = 0, best = N;

    for (int a : A)
        if (freq[a]++ == 1)
            duplicates++;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && duplicates > 0)
            if (--freq[A[j++]] == 1)
                duplicates--;

        if (duplicates == 0)
            best = min(best, j - i);

        if (freq[A[i]]++ == 1)
            duplicates++;
    }

    cout << best << '\n';
}