#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=100010;
int a[N],b[N],n,m,n1,n2,v,q;
int cal1(int x1,int y1,int x2,int y2)
{
	if(!n1)return (int)2e9;
	if(x1==x2)return y2-y1;
	int pos=lower_bound(a+1,a+n1+1,y1)-a;
	if(pos>n1)return y1+y2-2*a[pos-1]+abs(x1-x2);
	else if(a[pos]<=y2)return y2-y1+abs(x1-x2);
	else if(pos==1)return 2*a[pos]-y2-y1+abs(x1-x2);
	else return min(y2+y1-2*a[pos-1],2*a[pos]-y2-y1)+abs(x1-x2);
}
int cal2(int x1,int y1,int x2,int y2)
{
	if(!n2)return (int)2e9;
	if(x1==x2)return y2-y1;
	int pos=lower_bound(b+1,b+n2+1,y1)-b;
	if(pos>n2)return y1+y2-2*b[pos-1]+(abs(x1-x2)-1)/v+1;
	else if(b[pos]<=y2)return y2-y1+(abs(x1-x2)-1)/v+1;
	else if(pos==1)return 2*b[pos]-y2-y1+(abs(x1-x2)-1)/v+1;
	else return min(y2+y1-2*b[pos-1],2*b[pos]-y2-y1)+(abs(x1-x2)-1)/v+1;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&v);
	rep(i,n1)scanf("%d",&a[i]);
	rep(i,n2)scanf("%d",&b[i]);
	scanf("%d",&q);
	rep(i,q)
	{
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(y1>y2)swap(y1,y2);
		printf("%d\n",min(cal1(x1,y1,x2,y2),cal2(x1,y1,x2,y2)));
	}
    return 0;
}