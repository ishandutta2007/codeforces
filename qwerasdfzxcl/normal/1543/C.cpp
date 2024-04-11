#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const double eps = 0.000001;

double calc(double c, double m, double p, double v){
    //printf("%lf %lf %lf %lf\n", c, m, p, v);
    if (c<eps && m<eps) return 1;
    double ret = p, x, y;
    if (c<eps){
        x = min(m, v);
        ret += m*(calc(c, m-x, p+x, v)+1);
        return ret;
    }
    if (m<eps){
        x = min(c, v);
        ret += c*(calc(c-x, m, p+x, v)+1);
        return ret;
    }
    x = min(c, v), y = min(m, v);
    ret += c*(calc(c-x, m+x/2, p+x/2, v)+1);
    ret += m*(calc(c+y/2, m-y, p+y/2, v)+1);
    return ret;
}

void solve(){
    double c, m, p, v;
    scanf("%lf %lf %lf %lf", &c, &m, &p, &v);
    printf("%.15lf\n", calc(c, m, p, v));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}