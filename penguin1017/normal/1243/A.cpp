#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
int a[1009];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		rep(i,0,n)scanf("%d",&a[i]);
		sort(a,a+n);
		int tot=0;
		per(i,0,n){
			if(tot+1<=a[i])tot++;
			else break;
		}
		printf("%d\n",tot);
	}
}