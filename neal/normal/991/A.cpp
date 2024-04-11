#include <iostream>
using namespace std;

int A, B, C, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C >> N;
    int celebrate = A + B - C;

    if (A < N && B < N && C <= min(A, B) && celebrate < N) {
        cout << N - celebrate << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}