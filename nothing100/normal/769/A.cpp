#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn =  110;
int n;
int a[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    printf("%d\n", a[(n+1)/2]);
}