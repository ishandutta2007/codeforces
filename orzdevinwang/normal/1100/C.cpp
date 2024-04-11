#include<bits/stdc++.h>
#define R(i, j, k) for(int i = j; i <= k; i++)
#define L(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
double n, r, pi = acos(-1);
int main() {
    scanf("%lf%lf", &n, &r);
    double qwq = sin(pi / n);
    printf("%.7lf", r / (1 - qwq) - r);
    return 0;
}