#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int a[1000010];
void calc(int n) {
    if (n<1) return;
    int p=0;
    for (;(1<<p)<=n;p++);
    p--;
    int j=1<<p;
    for (int i=1<<p; i<=n; i++) {
	j--;
	a[i]=j;
	a[j]=i;
    }
    calc(j-1);
}
int main() {
    int n;
    scanf("%d", &n);
    calc(n);
    cout<<LL(n)*(n+1)<<endl;
    for (int i=0; i<=n; i++) printf("%d%c", a[i], i==n?'\n':' ');

    return 0;
}