#include <bits/stdc++.h>

using namespace std;
long long n, d, m, maxi, sum, x, y, a, b;
vector<long long> kis, nagy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> d >> m;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        if (x>m) nagy.push_back(x);
        else kis.push_back(x), sum+=x;
    }
    x=kis.size(), y=nagy.size(), a=x;
    sort(nagy.rbegin(), nagy.rend()), sort(kis.rbegin(), kis.rend());
    for (int i=0; i<(n-x+d)/(d+1); i++) sum+=nagy[b], b++;
    maxi=sum;
    while(b<y) {
        sum+=nagy[b], b++;
        while((b-1)*d-y+b-x+a>0 && a) a--, sum-=kis[a];
        if ((b-1)*d-y+b-x+a==0) maxi=max(maxi, sum);
        else break;
    }
    cout << maxi << "\n";
    return 0;
}