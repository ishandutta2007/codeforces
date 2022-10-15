#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef double ld;
ld ans[100001];
int ansPos;

int main() {
    ansPos = 0;
    int n;
    ld a,d;
    scanf("%d %lf %lf", &n, &a, &d);
    //cin>>n>>a>>d;
    ld cute = -1e15;
    for(int i = 0; i < n; ++i) {
        ld t, v;
     //   cin>>t>>v;
        scanf("%lf %lf", &t, &v);
        /*
        if(v < mv) {
            mv = v;
            mt = t;
            continue;
        }
        */
        ld lo = 0;
        ld lol = v/a;
        if(lol*lol*a/2 >= d) {
            lo = sqrt(d/a*2);
        }
        else {
            ld q = d - lol*lol*a/2;
            lo = lol + q/v;
        }
        if(lo+t < cute) {
            //cout<<cute<<'\n';
            ans[ansPos] =(cute);
            ++ansPos;

        }
        else {
            //cout<<fixed;
            //cout<<setprecision(10)<<lo+t<<'\n';
            ans[ansPos] = lo+t;
            ++ansPos;
            cute = lo+t;
        }
    }
    for(int i = 0; i < ansPos; ++i) {
        //cout<<setprecision(10)<<ans[i]<<'\n';
        printf("%.10f \n", ans[i]);
    }
}