#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double A, B, C;

double x_intersect(double y) {
    return -(B * y + C) / A;
}

double y_intersect(double x) {
    return -(A * x + C) / B;
}

double manhattan(double x1, double y1, double x2, double y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

double euclidean(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    double X1, Y1, X2, Y2;
    cin >> A >> B >> C;
    cin >> X1 >> Y1 >> X2 >> Y2;
    double answer = manhattan(X1, Y1, X2, Y2);

    if (A == 0 || B == 0) {
        printf("%.12lf\n", answer);
        return 0;
    }

    double x_line[2][2], y_line[2][2];

    x_line[0][0] = x_intersect(Y1);
    y_line[0][0] = Y1;

    x_line[0][1] = X1;
    y_line[0][1] = y_intersect(X1);

    x_line[1][0] = x_intersect(Y2);
    y_line[1][0] = Y2;

    x_line[1][1] = X2;
    y_line[1][1] = y_intersect(X2);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            answer = min(answer, manhattan(X1, Y1, x_line[0][i], y_line[0][i]) +
                                 euclidean(x_line[0][i], y_line[0][i], x_line[1][j], y_line[1][j]) +
                                 manhattan(x_line[1][j], y_line[1][j], X2, Y2));

    printf("%.12lf\n", answer);
}