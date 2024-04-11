#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;


int main() {
    int n;
    int ans=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	int k, a;
	LL t=1;
	scanf("%d%d", &k, &a);
	if (a==1) a++;;
	while (t<a) { k++; t*=4; }
	ans=max(ans, k);
    }
    printf("%d\n", ans);

    return 0;
}