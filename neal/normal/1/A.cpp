#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int N, M, A;
    scanf("%d %d %d", &N, &M, &A);
    cout << (long long) ((N - 1) / A + 1) * ((M - 1) / A + 1) << '\n';
    return 0;
}