#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct point {
    double x;
    double y;
    
    point(const double &x1 = 0, const double &y1 = 0) {
        x = x1;
        y = y1;
    }
} point;

typedef struct line {
    point p1;
    point p2;
    
    line(const point &s = point(), const point &t = point()) {
        p1 = s;
        p2 = t;
    }
} line;

double eps = 1e-8;

bool operator<(const point &a, const point &b)
{
    if (abs(a.x - b.x) > eps) return a.x < b.x;
    
    return a.y < b.y;
}

bool operator==(const point &a, const point &b)
{
    return abs(a.x - b.x) < eps && abs(a.y - b.y) < eps;
}

point operator+(const point &a, const point &b)
{
    return point(a.x + b.x, a.y + b.y);
}

point operator-(const point &a, const point &b)
{
    return point(a.x - b.x, a.y - b.y);
}

point operator*(const point &a, const double &r)
{
    return point(a.x * r, a.y * r);
}

point operator/(const point &a, const double &r)
{
    return point(a.x / r, a.y / r);
}

inline double area(const point &p1, const point &p2, const point &p3)
{
    point p = p1 - p3;
    point q = p2 - p3;
    
    return abs(p.x * q.y - p.y * q.x) / 2;
}

enum {
    LEFT = 1,
    RIGHT = -1,
    FRONT = 2,
    BACK = -2,
    ON = 0
};

inline int ccw(const point &p1, const point &p2, const point &p3)
{
    point p = p2 - p1;
    point q = p3 - p1;
    double r = p.x * q.y - p.y * q.x;
    
    if (r > eps) {
        return LEFT;
    } else if (r < -eps) {
        return RIGHT;
    } else {
        double t = (p.x * q.x + p.y * q.y) / (p.x * p.x + p.y * p.y);
        
        if (t > 1) {
            return FRONT;
        } else if (t < 0) {
            return BACK;
        } else {
            return ON;
        }
    }
}

inline bool cross(const line &l1, const line &l2)
{
    return ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2) <= 0 && ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2) <= 0;
}

int n, m = 1000000007;
int f[201][201];
long long dp[201][201][201];
vector <point> v;

int dfs(int x, int y, int z)
{
    int i, j;
    long long ans = 0;
    
    if (dp[x][y][z] != -1) return dp[x][y][z];
    
    if (y + 1 >= z) return dp[x][y][z] = 1;
    
    for (i = y; i <= z; i++) {
        if (f[x][i] == 0 || f[y][i] == 0) continue;
        if (ccw(v[x], v[y], v[i]) != LEFT) continue;
        
        ans += (long long)dfs(i, y, i) * dfs(x, i, z) % m;
        if (ans >= m) ans -= m;
    }
    
    return dp[x][y][z] = ans;
}

int main()
{
    int i, j, k;
    double sum = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(point(x, y));
    }
    
    for (i = 2; i < n; i++) {
        double s = area(v[0], v[i - 1], v[i]);
        
        if (ccw(v[0], v[i - 1], v[i]) == RIGHT) s = -s;
        
        sum += s;
    }
    
    if (sum < 0) reverse(v.begin(), v.end());
    
    v.push_back(v[0]);
    
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v.size(); j++) {
            line l = line(v[i], v[j]);
            
            if (v[i] == v[j]) continue;
            
            for (k = 0; k < v.size() - 1; k++) {
                if (v[i] == v[k] || v[j] == v[k]) continue;
                if (v[i] == v[k + 1] || v[j] == v[k + 1]) continue;
                
                if (cross(l, line(v[k], v[k + 1]))) break;
            }
            
            if (k == v.size() - 1) f[i][j] = 1;
        }
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= n; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    printf("%d", dfs(0, 1, n));
    printf("\n");
    
    return 0;
}