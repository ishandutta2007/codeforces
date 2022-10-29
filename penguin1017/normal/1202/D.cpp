#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back 
#define lowbit(x) ((x)&(-x))
#define ll long long
using namespace std;
const int N=(int)1e5+9;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,Sqr,a,b,c;
		scanf("%d",&n);
		if(n<99995){
			rep(i,0,n)printf("1");
			printf("337\n");
			continue;
		}
		a=33331;
		n-=2*a;
		c=n/a;
		b=n%a;
		rep(i,0,a)printf("1");
		printf("3");
		rep(i,0,b)printf("1");
		printf("3");
		rep(i,1,c)printf("7");
		printf("37\n");
	}
}