#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[100050];
int main(){
    int n, n1, n2;
    scanf("%d%d%d", &n, &n1, &n2);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    long long tot1=0, tot2=0;
    int bp=min(n1, n2);
    int e=max(n1, n2);
    for(int i=0; i<bp; i++) tot1+=a[n-1-i];
    for(int i=0; i<e; i++) tot2+=a[n-1-i-bp];
    double ave=(double)tot1/(double)bp+(double)tot2/(double)e;
    //cout<<ave<<endl;
    printf("%.8f\n", ave);
    return 0;
}