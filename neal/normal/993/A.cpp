#include <cassert>
#include <iostream>
using namespace std;

const int INF = 1e9 + 5;

struct square {
    int x[4], y[4];
};

square first, second;

int min_x = INF;
int max_x = -INF;
int min_y = INF;
int max_y = -INF;

int center_x = 0;
int center_y = 0;
int dist = 0;

bool in_first_square(int x, int y) {
    return min_x <= x && x <= max_x && min_y <= y && y <= max_y;
}

int get_dist(int x, int y) {
    return abs(x - center_x) + abs(y - center_y);
}

bool in_second_square(int x, int y) {
    return get_dist(x, y) <= dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++)
        cin >> first.x[i] >> first.y[i];

    for (int i = 0; i < 4; i++)
        cin >> second.x[i] >> second.y[i];

    for (int i = 0; i < 4; i++) {
        min_x = min(min_x, first.x[i]);
        max_x = max(max_x, first.x[i]);
        min_y = min(min_y, first.y[i]);
        max_y = max(max_y, first.y[i]);
    }

    for (int i = 0; i < 4; i++) {
        center_x += second.x[i];
        center_y += second.y[i];
    }

    assert(center_x % 4 == 0 && center_y % 4 == 0);
    center_x /= 4;
    center_y /= 4;
    dist = get_dist(second.x[0], second.y[0]);
    // cerr << min_x << ' ' << max_x << ' ' << min_y << ' ' << max_y << '\n';
    // cerr << center_x << ' ' << center_y << '\n';

    for (int i = 0; i < 4; i++)
        assert(get_dist(second.x[i], second.y[i]) == dist);

    bool answer = false;

    // for (int i = 0; i < 4; i++) {
    //     // if (in_first_square(second.x[i], second.y[i]))
    //     //     cerr << second.x[i] << ' ' << second.y[i] << '\n';

    //     // if (in_second_square(first.x[i], first.y[i]))
    //     //     cerr << first.x[i] << ' ' << first.y[i] << '\n';

    //     answer = answer || in_first_square(second.x[i], second.y[i]);
    //     answer = answer || in_second_square(first.x[i], first.y[i]);
    // }

    for (int x = min_x; x <= max_x; x++)
        for (int y = min_y; y <= max_y; y++)
            if (in_second_square(x, y))
                answer = true;

    for (int x = center_x - dist; x <= center_x + dist; x++)
        for (int y = center_y - dist; y <= center_y + dist; y++)
            if (get_dist(x, y) <= dist && in_first_square(x, y))
                answer = true;

    cout << (answer ? "YES" : "NO") << '\n';
    return 0;
}