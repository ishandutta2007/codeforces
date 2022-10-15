#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, w;
vector<int> a;

int main() {
    cin >> n >> w;
    a.resize(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    double t1 = a[0];
    double t2 = a[n-1];
    double t3 = a[n];
    double t4 = a[2*n-1];
    double k;
    if (2*t1 <= t3) k = t1;
    else k = t3/2;
    printf("%.9lf\n", min((double)w,n*k+n*2*k)); 
}