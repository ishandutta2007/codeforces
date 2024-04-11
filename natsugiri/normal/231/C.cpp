#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

int n, k;
int a[100010];
LL v[100010], l[100010], p;

int main(){
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    sort(a, a+n);
    l[0]=1;
    p=0;
    for (int i=1; i<n; i++) {
	LL x=l[i-1]*(a[i]-a[i-1])+v[i-1];
	for (;x>k;) { x-=a[i]-a[p]; p++; }
	l[i]=i-p+1; v[i]=x;
    }
    p=0;
    for (int i=1; i<n; i++) if (l[p]<l[i]) p=i;
    cout<<l[p]<<' '<<a[p]<<endl;
  return 0;
}