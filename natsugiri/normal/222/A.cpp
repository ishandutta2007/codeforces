#include<cstdio>
#include<iostream>
using namespace std;



int n, k;
int a[100010];
int main() {
    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d", a+i);
    for (int i=k; i<n; i++) if (a[k-1]!=a[i]) { puts("-1"); return 0; }
    int ans=k-1;
    for (int i=k-2; i>=0 && a[i]==a[k-1]; i--) ans--;
    printf("%d\n", ans);

    return 0;
}