#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<int> correct;

int ask(int number) {
    cout << number << endl;

    int answer;
    cin >> answer;

    if (answer == 0 || answer == -2)
        exit(0);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    correct.resize(N);

    for (int i = 0; i < N; i++)
        correct[i] = ask(1);

    int low = 2, high = M;
    int iteration = 0;

    while (low < high) {
        int mid = (low + high) / 2;

        if (ask(mid) == correct[iteration % N])
            low = mid + 1;
        else
            high = mid - 1;

        iteration++;
    }

    ask(low);
    return 0;
}