#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, location;
vector<bool> winnable;

int main() {
    scanf("%d", &N);
    A.resize(N);
    location.resize(N + 1);
    winnable.assign(N, false);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        location[A[i]] = i;
    }

    for (int num = N; num > 0; num--) {
        int loc = location[num];
        winnable[loc] = false;

        for (int i = loc % num; i < N; i += num)
            if (i != loc && A[i] > num && !winnable[i])
                winnable[loc] = true;
    }

    for (int i = 0; i < N; i++)
        putchar(winnable[i] ? 'A' : 'B');

    putchar('\n');
}