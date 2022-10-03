#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 100000000000ll
int n,y[MN],t;
ll x,k[MN];
char s[120];
int main(){
	scanf("%d",&n);
	k[0]=1;
	while(n--){
		scanf("%s",s);
		if(*s=='f'){
			++t;
			scanf("%d",&y[t]);
			k[t]=k[t-1]*y[t];
			if(k[t]>=inf)k[t]=inf;
		}
		if(*s=='e'){
			--t;
		}
		if(*s=='a'){
			x+=k[t];
			if(x>=inf)x=inf;
		}
	}
	if(x>4294967295ll)puts("OVERFLOW!!!");
	else printf("%lld\n",x);
	return 0;
}