#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> answer(N, 0);

    for (int i = 1; i < N; i++)
        if (S[i] == 'a') {
            answer[i - 1] ^= 1;
            answer[i] ^= 1;
        }

    for (int i = 0; i < N; i++)
        printf("%d%c", answer[i], i < N - 1 ? ' ' : '\n');
}