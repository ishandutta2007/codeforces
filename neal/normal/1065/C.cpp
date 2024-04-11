#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> H(N);

    for (int &h : H)
        scanf("%d", &h);

    sort(H.rbegin(), H.rend());
    int goal = H.back();
    int index = 0, count = 0, slices = 0;

    for (int height = H[0]; height >= goal; height--) {
        while (index < N && H[index] > height)
            index++;

        if (count + index > K) {
            count = 0;
            slices++;
        }

        count += index;
    }

    if (count > 0) {
        count = 0;
        slices++;
    }

    printf("%d\n", slices);
}