#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

const int SE_MAX = 100005, INF = 1000000005;

int N, M, S, E, V, Q;
int stairs[SE_MAX];
int elevators[SE_MAX];

int get_distance(int y1, int y2, int x_diff, int location, int velocity) {
    return abs(y1 - location) + abs(y2 - location) + (x_diff + velocity - 1) / velocity;
}

int solve_via(int x1, int y1, int x2, int y2, int n, int locations[SE_MAX], int velocity) {
    if (n == 0) {
        return INF;
    }

    int x_diff = abs(x1 - x2);
    int position = lower_bound(locations, locations + n, min(y1, y2)) - locations;
    int distance = INF;

    if (position < n) {
        distance = get_distance(y1, y2, x_diff, locations[position], velocity);
    }

    position--;

    if (position >= 0) {
        distance = min(distance, get_distance(y1, y2, x_diff, locations[position], velocity));
    }

    return distance;
}

int solve(int x1, int y1, int x2, int y2) {
    if (x1 == x2)
        return abs(y1 - y2);

    int stairs_time = solve_via(x1, y1, x2, y2, S, stairs, 1);
    int elevator_time = solve_via(x1, y1, x2, y2, E, elevators, V);
    assert(stairs_time < INF || elevator_time < INF);
    return min(stairs_time, elevator_time);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S >> E >> V;
    // assert(scanf("%d %d %d %d %d", &N, &M, &S, &E, &V) == 5);

    for (int i = 0; i < S; i++) {
        cin >> stairs[i];
        // assert(scanf("%d", &stairs[i]) == 1);
    }

    for (int i = 0; i < E; i++) {
        cin >> elevators[i];
        // assert(scanf("%d", &elevators[i]) == 1);
    }

    sort(stairs, stairs + S);
    sort(elevators, elevators + E);

    cin >> Q;
    // assert(scanf("%d", &Q) == 1);

    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // assert(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4);
        cout << solve(x1, y1, x2, y2) << '\n';
        // printf("%d\n", solve(x1, y1, x2, y2));
    }

    return 0;
}