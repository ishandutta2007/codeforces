#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int LETTERS = 26;

int N;
string T;

int main() {
    cin >> T;
    N = T.size();

    string first = "", second = "", third = "";

    for (int i = 0; i < N; i++) {
        first += 'a' + i / (LETTERS * LETTERS) % LETTERS;
        second += 'a' + i / LETTERS % LETTERS;
        third += 'a' + i % LETTERS;
    }

    string first_result, second_result, third_result;

    cout << "? " << first << endl;
    cin >> first_result;

    cout << "? " << second << endl;
    cin >> second_result;

    cout << "? " << third << endl;
    cin >> third_result;

    vector<int> permutation(N, -1);

    for (int position = 0; position < N; position++) {
        int index = -1;

        for (int i = 0; i < N; i++)
            if (first_result[i] == first[position] && second_result[i] == second[position] && third_result[i] == third[position]) {
                assert(index < 0);
                index = i;
            }

        assert(index >= 0);
        permutation[position] = index;
    }

    string answer = T;

    for (int i = 0; i < N; i++)
        answer[i] = T[permutation[i]];

    cout << "! " << answer << endl;
}