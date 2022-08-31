#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int r_sum = 0, c_sum = 0, count = 0;

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= M; c++) {
            char cell;
            cin >> cell;

            if (cell == 'B') {
                r_sum += r;
                c_sum += c;
                count++;
            }
        }

    cout << r_sum / count << ' ' << c_sum / count << '\n';
    return 0;
}