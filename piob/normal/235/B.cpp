#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n;
typedef long double K;
K p, w, r;

int main(){
/*#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    cin >> n;
    r = w = 0;
    FWD(i,0,n){
        cin >> p;
        r += p * (2*w+1);
        w = (w+1)*p;
    }
    cout << fixed << r;
    return 0;
}