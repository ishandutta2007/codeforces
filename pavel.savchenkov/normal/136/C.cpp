#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
     scanf("%d",&a[i]);
    sort(a,a+n); if (a[n-1]!=1) a[n-1]=1; else a[n-1]=2; sort(a,a+n);
    for (int i=0;i<n;i++)
     printf("%d ",a[i]);
    return 0;
}