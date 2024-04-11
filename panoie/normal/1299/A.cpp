#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, ans, id, a[N], s[N], f[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), s[i]=s[i-1]|a[i];
	for(int i=n; i; --i) f[i]=f[i+1]|a[i];
	ans=-1;
	for(int i=1; i<=n; ++i){
		int x=s[i-1]|f[i+1];
		x=(a[i]|x)-x;
		if(x>ans) ans=x, id=i;
	}
	printf("%d ", a[id]);
	for(int i=1; i<id; ++i) printf("%d ", a[i]);
	for(int i=id+1; i<=n; ++i) printf("%d ", a[i]);
	return 0;
}