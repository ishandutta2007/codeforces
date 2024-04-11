#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 5205;

int N;
bitset<N_MAX> matrix[N_MAX];
int rect_sum[N_MAX][N_MAX];

int hex_to_int(char hex) {
    return isdigit(hex) ? hex - '0' : hex - 'A' + 10;
}

int get_rect_sum(int r1, int r2, int c1, int c2) {
    return rect_sum[r2][c2] - rect_sum[r2][c1] - rect_sum[r1][c2] + rect_sum[r1][c1];
}

int main() {
    scanf("%d", &N);
    char str[N_MAX];

    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        reverse(str, str + N / 4);

        for (int j = 0; j < N; j++)
            matrix[i][j] = (hex_to_int(str[j / 4]) >> j % 4) & 1;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            rect_sum[i + 1][j + 1] = rect_sum[i + 1][j] + rect_sum[i][j + 1] - rect_sum[i][j] + matrix[i][j];

    for (int x = N; x > 0; x--)
        if (N % x == 0) {
            bool good = true;

            for (int i = 0; i < N && good; i += x)
                for (int j = 0; j < N && good; j += x) {
                    int sum = get_rect_sum(i, i + x, j, j + x);

                    if (sum != x * x && sum != 0)
                        good = false;
                }

            if (good) {
                cout << x << '\n';
                return 0;
            }
        }

    assert(false);
}