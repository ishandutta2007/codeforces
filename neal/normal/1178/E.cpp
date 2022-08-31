#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();

    int first = 0, last = N - 1;
    string forward = "", backward = "";

    while (first < last) {
        if (last - first + 1 >= 4) {
            bool finished = false;

            for (int a = first; a <= first + 1 && !finished; a++)
                for (int b = last; b >= last - 1 && !finished; b--)
                    if (S[a] == S[b]) {
                        forward += S[a];
                        backward += S[b];
                        finished = true;
                    }

            assert(finished);
            first += 2;
            last -= 2;
        } else {
            forward += S[first];
            break;
        }
    }

    reverse(backward.begin(), backward.end());
    cout << forward + backward << '\n';
}