#include<bits/stdc++.h>
using namespace std;
int n;
double now,ans;
double s;
int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%lf",&s);
		ans=ans+s*(now*2+1),now=(1+now)*s;
	}
	printf("%.10lf",ans);
	return 0;
}