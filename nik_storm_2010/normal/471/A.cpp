#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector <int> a(6);
    for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] < a[5]) {
        puts("Bear");
        return 0;
    }
    if (a[0] < a[1] && a[2] == a[3] && a[3] == a[4] && a[4] == a[5]) {
        puts("Bear");
        return 0;
    }
    if (a[0] < a[5] && a[1] == a[2] && a[2] == a[3] && a[3] == a[4]) {
        puts("Bear");
        return 0;
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] == a[5]) {
        puts("Elephant");
        return 0;
    }
    if (a[0] == a[1] && a[2] == a[3] && a[3] == a[4] && a[4] == a[5]) {
        puts("Elephant");
        return 0;
    }
    puts("Alien");
    return 0;
}