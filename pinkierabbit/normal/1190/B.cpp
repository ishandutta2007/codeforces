#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define win return puts("sjfnb"),0
#define lose return puts("cslnb"),0
int n;
int a[MN],b[MN];
int main(){
	int t2=0,pos=0;
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	F(i,1,n-1)if(a[i]==a[i+1])++t2,pos=i;
	if(t2>1)lose;
	ll moves=0;
	if(t2==1){
		if(!a[pos])lose;
		--a[pos];
		if(pos>1&&a[pos-1]==a[pos])lose;
		++moves;
	}
	F(i,1,n)moves+=a[i]-i+1;
	if(moves&1)win;
	else lose;
	return 0;
}