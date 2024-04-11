#include <bits/stdc++.h>

using namespace std;
long long w, t[7], n, m;
long long ans(int a, int b) {
    long long x=0, y=0, sum=0;
    if (a==1) x=m, y=-n;
    else if (b==1) x=n, y=m-x;
    else x=m, y=x-n;
    if (x>0) sum+=x*t[a];
    else sum-=x*t[a+3];
    if (y>0) sum+=y*t[b];
    else sum-=y*t[b+3];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        for (int i=0; i<6; i++) cin >> t[i];
        cout << min({ans(0, 1), ans(1, 2), ans(0, 2)}) << "\n";
    }
    return 0;
}