#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int XA, YA, XB, YB, XC, YC;
vector<pair<int, int>> plots;

void go(int x, int y, int goal_x, int goal_y) {
    while (x != goal_x) {
        if (x < goal_x)
            x++;
        else
            x--;

        plots.emplace_back(x, y);
    }

    while (y != goal_y) {
        if (y < goal_y)
            y++;
        else
            y--;

        plots.emplace_back(x, y);
    }
}

int median(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    return b;
}

int main() {
    cin >> XA >> YA >> XB >> YB >> XC >> YC;
    int start_x = median(XA, XB, XC);
    int start_y = median(YA, YB, YC);
    plots = {{start_x, start_y}};
    go(start_x, start_y, XA, YA);
    go(start_x, start_y, XB, YB);
    go(start_x, start_y, XC, YC);
    printf("%d\n", (int) plots.size());

    for (pair<int, int> p : plots)
        printf("%d %d\n", p.first, p.second);
}