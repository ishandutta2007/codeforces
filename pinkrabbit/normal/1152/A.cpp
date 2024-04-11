#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,c1,c2,d1,d2;
int main(){
	int x;
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",&x),++(x&1?c1:c2);
	F(i,1,m)scanf("%d",&x),++(x&1?d1:d2);
	printf("%d\n",min(c1,d2)+min(d1,c2));
	return 0;
}