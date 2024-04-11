#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i < b;i++)
#define pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define N 1000004
#define INF 1e9+7
 
using namespace std;
 
ll a,b,m;
double x,y,z;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> m;
    cin >> x >> y >> z;
    double t = -m/y;
    double dx = t*x;
    double x0 = a/2.0+dx;
    if(x0 < 0)
    {
        x0 = -x0;
    }
    x0 = fmod(x0,2.0*a);
    double z0 = fmod(t*z,2.0*b);
    if(x0 >= a)
    {
        x0 = 2*a - x0;
    }
    if(z0 >= b)
    {
        z0 = 2*b - z0;
    }
    cout << fixed << setprecision(10) << x0 << " " << z0 << endl;
}