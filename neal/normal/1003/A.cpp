#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<int, int> pockets;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        int number;
        cin >> number;
        answer = max(answer, ++pockets[number]);
    }

    cout << answer << '\n';
    return 0;
}