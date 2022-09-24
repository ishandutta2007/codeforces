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


int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double s = sqrt(max(0.0, b*b-4*a*c));
    double ans[] = {(-b+s)/(2*a), (-b-s)/(2*a)};
    sort(ans, ans+2);
    printf("%.20f\n", ans[1]);
    printf("%.20f\n", ans[0]);
    return 0;
}