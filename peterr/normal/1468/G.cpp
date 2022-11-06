#include <bits/stdc++.h>

using namespace std;

struct Pt
{
    double x, y;

    double norm()
    {
        return sqrt(x * x + y * y);
    }

    Pt operator*(double scalar)
    {
        return {x * scalar, y * scalar};
    }

    Pt operator+(const Pt& other)
    {
        return {x + other.x, y + other.y};
    }

    Pt operator-(const Pt& other)
    {
        return {x - other.x, y - other.y};
    }

    friend ostream& operator<<(ostream& out, const Pt& pt)
    {
        out << "(" << pt.x << ", " << pt.y << ")";
        return out;
    }

    double cross(const Pt& other)
    {
        return x * other.y - y * other.x;
    }
};

const int INTER = 0;
const int INCIDENT = 1;
const int PARALLEL = 2;
const int MAXN = 2E5;
Pt points[MAXN];

int lineIntersect(Pt p, Pt r, Pt q, Pt s, Pt &result, double &param)
{
    //cout << "intersecting" << endl;
    //cout << p << endl << r << endl << q << endl << s << endl;
    double det = s.cross(r);
    if (det == 0)
    {
        return PARALLEL;
        /*
        if (s.cross(p - (q + s)) == 0)
            return INCIDENT;
        return PARALLEL;
        */
    }
    else
    {
        param = (-s.y * (q.x - p.x) + s.x * (q.y - p.y)) / det;
        if (param >= 0 && param <= 1)
            result = p + r * param;
        return INTER;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        //cout << "pt " << i << " " << points[i] << endl;
    }
    reverse(points, points + n);
    double ans = 0;
    Pt cur = points[0];
    Pt peak = points[0];
    Pt eye = {points[0].x, points[0].y + h};
    for (int i = 1; i < n; i++)
    {
        Pt toPeak = peak - eye;
        if (toPeak.cross(cur - peak) <= 0 && toPeak.cross(points[i] - peak) <= 0)
        {
            //cout << "full " << i << endl;
            ans += (points[i] - cur).norm();
        }
        else
        {
            Pt above = points[i];
            Pt below = cur;
            if (toPeak.cross(above - peak) > 0)
                swap(above, below);
            Pt result = {0, 0};
            double param = -1;
            int code = lineIntersect(above, below - above, eye, peak - eye, result, param);
            //cout << "iter " << i << endl;
            //cout << "above " << above << endl;
            //cout << "below " << below << endl;
            //cout << "param " << param << endl;
            //cout << "result " << result << endl;
            if (code == INTER && param >= 0 && param <= 1)
            {
                //cout << "partial " << i << " " << (result - above).norm() << endl;
                ans += (result - above).norm();
            }
        }
        cur = points[i];
        if ((peak - eye).cross(cur - peak) < 0)
            peak = cur;
        //cout << "peak iter " << i << " " << peak << endl;
    }
    cout << fixed << setprecision(7) << ans << "\n";
    return 0;
}