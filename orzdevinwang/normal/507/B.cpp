#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
db r, xa, ya, xb, yb;
int main() {
    scanf("%lf%lf%lf%lf%lf", &r, &xa, &ya, &xb, &yb);
    db len = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    printf("%d\n", (int)ceil(len / (r * 2)));
    return 0;
}