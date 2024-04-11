#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    while (Q-- > 0) {
        long long N;
        cin >> N;
        vector<int> ternary;

        for (long long x = N; x != 0; x /= 3)
            ternary.push_back(x % 3);

        ternary.push_back(0);

        while (find(ternary.begin(), ternary.end(), 2) != ternary.end()) {
            int index = -1;

            for (int i = 0; i < (int) ternary.size(); i++)
                if (ternary[i] == 2)
                    index = i;

            for (int i = 0; i <= index; i++)
                ternary[i] = 0;

            ternary[index + 1]++;
        }

        long long value = 0, power = 1;

        for (int x : ternary) {
            value += x * power;
            power *= 3;
        }

        cout << value << '\n';
    }
}