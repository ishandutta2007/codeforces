#include <bits/stdc++.h>

using namespace std;
bool v[2];
long long w, n, k;
bool sol(long long a, long long b, int p) {
    if (k>=a) {
        if (p) return a;
        else return (b-k)%2;
    }
    if (!p) return sol((a+1)/2, a-1, 1);
    if (a%2==0) return (k+1)%2;
    return sol((a+1)/2, a-1, 0);
}
int main()
{
    cin >> w, v[1]=1;
    while(w--) {
        cin >> k >> n;
        bool a=v[sol(n+1, 2*n, 1)], b=v[sol(n/2+1, n, 1)];
        v[0]=a, v[1]=b;
    }
    cout << v[0] << " " << v[1];
    return 0;
}