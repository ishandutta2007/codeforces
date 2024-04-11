#include <bits/stdc++.h>
using namespace std;

int a[6];
vector< pair<double, double> > points;
double pi = 3.14159265358979323846264338;

int main() {
    for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
    double x = 0, y = 0;
    points.push_back(make_pair(x, y));
    for (int i = 0; i < 360; i += 60) {
        double radians = double(i) * pi / 180;
        x += a[i/60] * cos(radians);
        y += a[i/60] * sin(radians);
        points.push_back(make_pair(x, y));
    }
    double area = 0;
    for (int i = 0; i < 6; i++) area += points[i].first * points[(i+1)%6].second;
    for (int i = 0; i < 6; i++) area -= points[i].second * points[(i+1)%6].first;
    printf("%.0lf\n", area / (tan(pi / 3) * 0.5));

}