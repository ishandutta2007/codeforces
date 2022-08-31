#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool query(int cafe) {
    cout << "? " << cafe + 1 << endl;
    char result;
    cin >> result;
    return result == 'N';
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<bool> good(N, true);
    int block = max(K / 2, 1);
    int M = N / block;

    for (int jump = 1; jump < M; jump++)
        for (int start = 0; start < jump && start + jump < M; start++) {
            cout << 'R' << endl;

            for (int i = start; i < M; i += jump)
                for (int x = i * block; x < (i + 1) * block; x++)
                    good[x] = good[x] && query(x);
        }

    cout << "! " << accumulate(good.begin(), good.end(), 0) << endl;
}