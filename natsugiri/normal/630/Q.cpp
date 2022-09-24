#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const double PI = acos(-1);

double V3(double x) {
    return sqrt(2) / 12 * x*x*x;
}
double V4(double x) {
    return sqrt(2) / 6 * x*x*x;
}
double V5(double x) {
    double g = tan(54.0/180.0*PI) / 2;
    // eprintf("%f\n", g);
    double h = sqrt(3.0/4-g*g);
    return h * 2.5 * g / 3 * x*x*x;
}

int main() {
    int a, b, c;
    scanf("%d%d%d",&a, &b, &c);
    printf("%.12f\n", V3(a) + V4(b) + V5(c));
    return 0;
}