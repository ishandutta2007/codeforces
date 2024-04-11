#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int x;
        scanf("%d", &x);
        printf("%d\n", x / 2);
    }
}