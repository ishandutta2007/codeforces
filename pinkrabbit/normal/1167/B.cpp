#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
const int k[]={4,8,16,15,23,42};
int a,b,c,d,e,f,g=4*8*16*15*23*42;
int dd[1005][55];
int main(){
	for(int i=0;i<6;++i)
		for(int j=i+1;j<6;++j)
			dd[k[i]*k[j]][k[i]]=1,
			dd[k[i]*k[j]][k[j]]=1;
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d",&a);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d",&b);
	printf("? 3 4\n");
	fflush(stdout);
	scanf("%d",&c);
	printf("? 4 5\n");
	fflush(stdout);
	scanf("%d",&d);
	e=g/a/c;
	f=g/b/d;
	int x=0;
	for(int i=0;i<6;++i)
		if(dd[a][k[i]]&&dd[f][k[i]]){x=k[i];break;}
	printf("! ");
	printf("%d ",x);
	printf("%d ",x=a/x);
	printf("%d ",x=b/x);
	printf("%d ",x=c/x);
	printf("%d ",x=d/x);
	printf("%d\n",x=e/x);
	fflush(stdout);
	return 0;
}