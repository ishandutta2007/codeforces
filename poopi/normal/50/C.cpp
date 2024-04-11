                                                                        /* in the name of Allah */
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define EPS 1e-9

int sorted[400010];

bool eq(double a, double b){
        return fabs(a - b) < EPS;
}
bool ls(double a, double b){
        return a + EPS < b;
}
bool lseq(double a, double b){
        return a - EPS < EPS;
}
bool gr(double a, double b){
        return a - EPS > b;
}
bool greq(double a, double b){
        return a + EPS > b;
}
struct CompCHGS
{
        int m;
        double *x, *y;
        CompCHGS(int m, double *x, double *y): m(m), x(x), y(y) {}
        bool operator()(const int i1, const int i2) const
        {
                return (gr((x[i1] - x[m]) * (y[i2] - y[m]), (x[i2] - x[m]) * (y[i1] - y[m])) ||
                        (eq((x[i1] - x[m]) * (y[i2] - y[m]), (x[i2] - x[m]) * (y[i1] - y[m])) &&
                        greq(x[i1], min(x[i2], x[m])) && lseq(x[i1], max(x[i2], x[m])) &&
                        greq(y[i1], min(y[i2], y[m])) && lseq(y[i1], max(y[i2], y[m]))));
        }
};

double mult(double x1, double y1, double x2, double y2, double x3, double y3)
{
        return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

void convexHullGS(int n, double x[], double y[], vector<int> &ch)
{
        int i, m = 0;
        for (i = 0; i < n; i++)
        {
                sorted[i] = i;
                if (ls(y[i], y[m]) || (eq(y[i], y[m]) && ls(x[i], x[m])))
                        m = i;
        }
        sorted[0] = m;
        sorted[m] = 0;
        sort(sorted + 1, sorted + n, CompCHGS(m, x, y));
        for (i = n - 1; i > 1 &&
                eq((x[sorted[i]] - x[m]) * (y[sorted[i - 1]] - y[m]),
                (x[sorted[i - 1]] - x[m]) * (y[sorted[i]] - y[m])); i--);
        if (i > 1) reverse(sorted + i, sorted + n);

        ch = vector<int>();
        ch.push_back(sorted[0]);
        if (n > 1)
        {
                ch.push_back(sorted[1]);
                for (i = 2; i < n; i++)
                {
                        while (ch.size() > 1 &&
                                greq(mult(x[sorted[i]], y[sorted[i]], x[ch.back()], y[ch.back()],
                                x[ch[ch.size() - 2]], y[ch[ch.size() - 2]]), 0))
                                ch.pop_back();
                        ch.push_back(sorted[i]);
                }
                if (ch.size() > 2 && eq(mult(x[ch.front()], y[ch.front()], x[ch.back()],
                        y[ch.back()], x[ch[ch.size() - 2]], y[ch[ch.size() - 2]]), 0))
                        ch.pop_back();
        }
}

#define P pair<int, int>
int n;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
double x[400010], y[400010];
vector <int> ord;
vector <P> p;

int main(){
        cin >> n;
        double a, b;
        for(int i = 0; i < n; i++){
                scanf("%lf%lf", &a, &b);
                for(int j = 0; j < 4; j++)
                        p.push_back(P(a + dir[j][0], b + dir[j][1]));
        }
        sort(p.begin(), p.end());
        int m = 0;
        for(int i = 0; i < p.size(); i++){
                if(i == 0 || p[i] != p[i-1]){
                        x[m] = p[i].first;
                        y[m++] = p[i].second;
                }
        }
        convexHullGS(m, x, y, ord);
        long long res = 0;
        for(int i = 0; i < ord.size(); i++){
                int j = (i + 1) % ((int)ord.size());
                res += max(fabs(x[ord[i]] - x[ord[j]]), fabs(y[ord[i]] - y[ord[j]])) + EPS;
        }
        cout << res << endl;
        return 0;
}