#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct point {
    int x, y;
};

int N;
vector<point> points;

int main() {
    scanf("%d", &N);
    points.resize(N);
    int min_x = INF, max_x = -INF;
    int min_y = INF, max_y = -INF;

    for (point &p : points) {
        scanf("%d %d", &p.x, &p.y);
        min_x = min(min_x, p.x);
        max_x = max(max_x, p.x);
        min_y = min(min_y, p.y);
        max_y = max(max_y, p.y);
    }

    int perimeter = 2 * (max_x - min_x) + 2 * (max_y - min_y);
    int best = 0;

    for (int i = 0; i < N; i++) {
        int x_dist = max(max_x - points[i].x, points[i].x - min_x);
        int y_dist = max(max_y - points[i].y, points[i].y - min_y);
        best = max(best, 2 * (x_dist + y_dist));
    }

    for (int i = 3; i <= N; i++)
        printf("%d%c", i == 3 ? best : perimeter, i < N ? ' ' : '\n');
}