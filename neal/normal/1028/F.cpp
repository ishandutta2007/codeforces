#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

map<long long, set<pair<int, int>>> radius_map;
map<pair<int, int>, int> matched;

pair<int, int> canonical(int x, int y) {
    int g = __gcd(x, y);
    return make_pair(x / g, y / g);
}

int main() {
    int Q, points = 0;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        if (type < 3) {
            long long radius = (long long) x * x + (long long) y * y;
            int change = type == 1 ? +1 : -1;

            matched[canonical(x, y)] += change;

            if (type == 2)
                radius_map[radius].erase(make_pair(x, y));

            for (auto &p : radius_map[radius]) {
                pair<int, int> sum = canonical(x + p.first, y + p.second);
                matched[sum] += 2 * change;
            }

            if (type == 1)
                radius_map[radius].insert(make_pair(x, y));

            points += change;
        } else {
            printf("%d\n", points - matched[canonical(x, y)]);
        }
    }

    return 0;
}