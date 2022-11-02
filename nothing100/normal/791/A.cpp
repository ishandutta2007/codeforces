#include<bits/stdc++.h>
#define LL long long
#define inf 100000000
using namespace std;
int a,b,ans;
int main(){
	scanf("%d%d",&a,&b);
	while (a<=b){
		ans++;
		a*=3;
		b*=2;
	}
	printf("%d\n",ans);
}