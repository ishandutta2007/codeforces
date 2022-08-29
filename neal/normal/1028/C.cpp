#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct rectangle {
    int x1, y1, x2, y2;

    rectangle(int _x1 = -INF, int _y1 = -INF, int _x2 = INF, int _y2 = INF)
        : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    bool valid() const {
        return x1 <= x2 && y1 <= y2;
    }

    rectangle intersect(const rectangle &other) const {
        return rectangle(max(x1, other.x1), max(y1, other.y1), min(x2, other.x2), min(y2, other.y2));
    }
};

int N;
vector<rectangle> rectangles, prefix;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    rectangles.resize(N);
    prefix.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
        prefix[i + 1] = prefix[i].intersect(rectangles[i]);
    }

    rectangle rect;

    for (int i = N - 1; i >= 0; i--) {
        rectangle inter = rect.intersect(prefix[i]);

        if (inter.valid()) {
            cout << inter.x1 << ' ' << inter.y1 << '\n';
            return 0;
        }

        rect = rect.intersect(rectangles[i]);
    }

    assert(false);
    return 0;
}