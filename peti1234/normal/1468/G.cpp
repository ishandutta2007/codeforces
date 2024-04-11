#include <bits/stdc++.h>

using namespace std;
struct pont {
    long double x;
    long double y;
};
int n, h;
pont szem, spec, bal, jobb, kozep, t[200002];
long double sum;
int f(pont a, pont b, pont c) {
    long double s=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if (s<0) return -1;
    if (s==0) return 0;
    if (s>0) return 1;
}
long double dist(pont a, pont b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        t[i].x=a, t[i].y=b;
    }
    spec=szem=t[n];
    szem.y+=h;
    for (int i=n; i>=2; i--) {
        bal=t[i-1], jobb=t[i];
        if (f(szem, spec, jobb)==-1) {
            spec=jobb;
        }
        for (int j=1; j<=60; j++) {
            kozep.x=(bal.x+jobb.x)/2;
            kozep.y=(bal.y+jobb.y)/2;
            if (f(szem, spec, kozep)==1) {
                jobb=kozep;
            } else {
                bal=kozep;
            }
        }
        sum+=dist(t[i-1], bal);
    }
    cout.precision(15);
    cout << sum << "\n";
    return 0;
}