#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1100000;
double a[maxn];
double b[maxn];

const double eps = 1e-8;
const double inf = 1e20;
int dcmp(double x) {
    return (x>eps)-(x<-eps);
}
int main() {
    //freopen("a.in","r",stdin);
    int n;
    double p;
    scanf("%d%lf", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &a[i], &b[i]);
    }
    double l = 0, r = inf;
    
    for (int t = 1; t <= 500; t++) {
        double mid = (l+r)/2;
        double sum = p*mid;
        for (int i = 1; i <= n; i++) {
            double tmp = b[i]-a[i]*mid;
            if (tmp < 0) sum += tmp;
        //    sum += b[i];
        //    sum -= a[i]*mid;
        }
        if (dcmp(sum) < 0) r = mid;
        else l = mid;
    }
    if (l > 1e19) printf("-1");
    else
    printf("%.8f\n", l);
}