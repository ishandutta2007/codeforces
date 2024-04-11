#include <bits/stdc++.h>

using namespace std;
long long p[70][2];
long long x, y, s, r, f=1, t, maxi;
long long sok=20000000000000000;
long long dist(long long a, long long b)
{
    return abs(p[a][0]-p[b][0])+abs(p[a][1]-p[b][1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> p[1][0] >> p[1][1];
    cin >> x >> y >> s >> r;
    while(p[f][0]<=sok && p[f][1]<=sok) {
        p[f+1][0]=p[f][0]*x+s;
        p[f+1][1]=p[f][1]*y+r;
        f++;
    }
    cin >> p[0][0] >> p[0][1] >> t;
    for (long long i=1; i<=f; i++) for (long long j=1; j<=f; j++) {
        if (dist(0, i)+dist(i, j)<=t) maxi=max(maxi, abs(i-j)+1);
    }
    cout << maxi << "\n";
    return 0;
}