#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
long long n;
long long x[8], y[8];
//
long long dist(int p1, int p2) {
        return (x[p2]-x[p1])*(x[p2]-x[p1])+(y[p2]-y[p1])*(y[p2]-y[p1]);
}
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        for (int i = 0; i < 8; i++)
                cin >> x[i] >> y[i];
        //
        for (int p1 = 0; p1 < 8; p1++)
                for (int p2 = 0; p2 < 8; p2++)
                        for (int p3 = 0; p3 < 8; p3++)
                                for (int p4 = 0; p4 < 8; p4++) {
                                        if (abs(x[p2]-x[p1]+0.0)+abs(y[p2]-y[p1]+0.0) > 0) {
                                                double m_x = (x[p1]+x[p2]+0.0)/2;
                                                double m_y = (y[p1]+y[p2]+0.0)/2;
                                                double d_y = m_y-(double)y[p1];
                                                double d_x = m_x-(double)x[p1];
                                                if ((2*x[p3] == int(2*(m_x-d_y))) && (2*y[p3] == int(2*(m_y+d_x))))
                                                        if ((2*x[p4] == int(2*(m_x+d_y))) && (2*y[p4] == int(2*(m_y-d_x)))) {
                                                                vector <int> points;
                                                                for (int i = 0; i < 8; i++)
                                                                        if (p1 != i && p2 != i && p2 != i && p4 != i)
                                                                                points.push_back(i);
                                                                //
                                                                bool ok = false;
                                                                do {
                                                                        if (abs(x[points[0]]-x[points[2]]+0.0)+abs(y[points[0]]-y[points[2]]+0.0) > 0) {
                                                                                if ((dist(points[0], points[1]) == dist(points[3], points[2])))
                                                                                        if ((dist(points[1], points[2]) == dist(points[3], points[0])))
                                                                                                if ((dist(points[0], points[2]) == dist(points[3], points[1])))
                                                                                                {
                                                                                                        ok = true;
                                                                                                        break;
                                                                                                }
                                                                        }
                                                                } while (next_permutation(points.begin(), points.end()));
                                                                //
                                                                if (ok) {
                                                                        cout << "YES" << endl;
                                                                        cout << p1 + 1 << " " << p2 + 1 << " " << p3 +1 << " " << p4 + 1 << endl;
                                                                        cout << points[0]+1 <<" " << points[1]+1 <<" "<<points[2]+1 << " " << points[3]+1<< endl;
                                                                        return 0;
                                                                }
                                                                //
                                                        }
                                        }
                                }
        //
        cout << "NO" << endl;
}