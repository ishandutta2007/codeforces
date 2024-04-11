#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
    int ind, deg;

    Point(long long x = 0, long long y = 0, int ind = 0, int deg = 0) : x(x), y(y), ind(ind), deg(deg) {}
};

long long distanceSquare(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

pair<pair<int, int>, double> findClosestPointsDistance(vector<Point> points) {
    assert(points.size() > 1);
    mt19937 rnd(1234);
    shuffle(points.begin(), points.end(), rnd);
    long long anssq = distanceSquare(points[0], points[1]);
    long long ans = sqrt(anssq);
    int i1 = points[0].ind, i2 = points[1].ind;
    if (anssq == 0) {
        return {{i1, i2}, ans};
    }
    unordered_map<long long, vector<Point>> grid;

    auto trueDivision = [&](long long a, long long b) -> long long {
        long long reminder = a % b;
        if (reminder < 0) {
            reminder += b;
        }
        return (a - reminder) / b;
    };
    auto getPointHash = [&](Point p) -> long long {
        return trueDivision(p.x, ans) * 10000007 + trueDivision(p.y, ans);
    };
    grid[getPointHash(points[0])].push_back(points[0]);
    grid[getPointHash(points[1])].push_back(points[1]);

    for (size_t i = 2; i < points.size(); i++) {
        long long newanssq = anssq;
        
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                for (Point q : grid[getPointHash(Point(points[i].x + dx * ans, points[i].y + dy * ans))]) {
                    if (newanssq > distanceSquare(points[i], q)) {
                        newanssq = distanceSquare(points[i], q);
                        i1 = points[i].ind;
                        i2 = q.ind;
                    }
                }
            }
        }

        if (newanssq < anssq) {
            anssq = newanssq;
            ans = sqrt(newanssq);
            if (anssq == 0) {
                return {{i1, i2}, ans};
            }
            grid.clear();
            for (size_t j = 0; j < i; j++) {
                grid[getPointHash(points[j])].push_back(points[j]);
            }
        }
        grid[getPointHash(points[i])].push_back(points[i]);
    }

    return {{i1, i2}, ans};
}

bool cmp(Point a, Point b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

int main()
{
  //  freopen("in.txt", "r", stdin);
#ifndef ONPC
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    /*auto trueDivision = [&](long long a, long long b) -> long long {
        long long reminder = a % b;
        if (reminder < 0) {
            reminder += b;
        }
        return (a - reminder) / b;
    };

    for (int i : vector<int>{6, -6, 16, -16}) {
        cerr << i << ' ' << i % 10 << ' ' << i / 10 << ' ' << (i - i % 10) <<  ' ' << trueDivision(i, 10) << endl;
    }
    return 0;*/
    int n;
    cout << fixed << setprecision(30);
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<Point> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
            a[i].ind = i + 1;
            a[i].deg = 1;
            if (a[i].x < 0)
            {
                a[i].x *= -1;
                if (a[i].y < 0)
                {
                    a[i].deg = 4;
                    a[i].y *= -1;
                }
                else
                    a[i].deg = 2;
            }
            else if (a[i].y < 0)
            {
                a[i].y *= -1;
                a[i].deg = 3;
            }
        }
        sort(a.begin(), a.end(), cmp);
        auto ans = findClosestPointsDistance(a);
        int i1 = 0;
        int i2 = 0;
        while (a[i1].ind != ans.first.first) {
            i1++;
            assert(i1 < n);
        }
        while (a[i2].ind != ans.first.second) {
            assert(i2 < n);
            i2++;
        }
        int &x = a[i1].deg;
        if (x == 1)
            x = 4;
        else if (x == 2)
            x = 3;
        else if (x == 3)
            x = 2;
        else
            x = 1;
        cout << a[i1].ind << " " << a[i1].deg << " ";
        cout << a[i2].ind << " " << a[i2].deg << "\n";
    }
    return 0;
}