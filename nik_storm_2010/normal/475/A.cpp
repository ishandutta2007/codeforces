#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

char a[10][30];

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < 6; i++) for (int j = 0; j < 26; j++) a[i][j] = '.';
    for (int j = 0; j < 26; j++) a[0][j] = a[5][j] = '-';
    a[0][0] = a[5][0] = a[0][25] = a[5][25] = '+';
    a[1][0] = a[2][0] = a[3][0] = a[4][0] = '|';
    a[1][25] = a[2][25] = a[3][25] = a[4][25] = '|';
    a[1][24] = 'D';
    a[1][23] = a[2][23] = a[4][23] = '|';
    int x = 1, y = 1;
    while (y != 23) {
        if (k > 0) a[x][y] = 'O'; else a[x][y] = '#';
        k--;
        x++;
        if (x == 5) {
            x = 1, y += 2;
        }
        if (x == 3 && y != 1) x++;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 26; j++) printf("%c", a[i][j]);
        if (i == 1 || i == 4) printf(")\n"); else printf("\n");
    }
    return 0;
}