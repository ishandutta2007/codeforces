#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- > 0) {
        int N;
        cin >> N;
        int answer = 0;

        for (int bit = 0; 1 << bit < N; bit++) {
            vector<int> left, right;

            for (int i = 0; i < N; i++)
                if (i & 1 << bit)
                    left.push_back(i + 1);
                else
                    right.push_back(i + 1);

            cout << left.size() << ' ' << right.size();

            for (int x : left)
                cout << ' ' << x;

            for (int x : right)
                cout << ' ' << x;

            cout << endl;
            int result;
            cin >> result;

            if (result == -1)
                return 0;

            answer = max(answer, result);
        }

        cout << -1 << ' ' << answer << endl;
    }
}