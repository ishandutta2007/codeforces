#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll l,r;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%lld%lld",&n,&l,&r);
	if(l==(ll)n*(n-1)+1){puts("1");continue;}
	int j=0;ll s=0;
	while(s<l)++j,s+=2*(n-j);
	s-=2*(n-j);
	int x=l-s;
	for(ll i=l;i<=min(r,(ll)n*(n-1));++i){
		printf("%d ",x&1?j:j+x/2);
		++x;
		if(x>2*(n-j))x=1,++j;
	}
	if(r==(ll)n*(n-1)+1)printf("1");
	puts("");
}	return 0;
}