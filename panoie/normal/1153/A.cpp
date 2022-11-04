#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

int n, t, ans=1e9, id;
int main() {
	scanf("%d%d", &n, &t);
	for(int i=1, x, y; i<=n; ++i){
		scanf("%d%d", &x, &y);
		int a;
		if(x>t) a=x-t; else a=(y-(t-x)%y)%y;
		if(a<ans) ans=a, id=i;
	}
	return printf("%d", id), 0;
}