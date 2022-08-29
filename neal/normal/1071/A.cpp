#include <iostream>
#include <vector>
using namespace std;

unsigned A, B;
vector<int> first_day, second_day;

void output(const vector<int> &vec) {
    int n = vec.size();
    printf("%d\n", n);

    for (int i = 0; i < n; i++)
        printf("%d%c", vec[i], i < n - 1 ? ' ' : '\n');
}

int main() {
    scanf("%u %u", &A, &B);
    unsigned n = 0;

    while (n * (n + 1) / 2 <= A + B)
        n++;

    n--;

    for (unsigned i = n; i > 0; i--)
        if (A >= i) {
            A -= i;
            first_day.push_back(i);
        } else {
            second_day.push_back(i);
        }

    output(first_day);
    output(second_day);
}