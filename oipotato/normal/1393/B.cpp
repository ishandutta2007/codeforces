#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int num[100010],num8,num6,num4,num2,n,q;
void add(int x)
{
	num[x]++;
	if(num[x]==8)num8++;
	if(num[x]==6)num6++;
	if(num[x]==4)num4++;
	if(num[x]==2)num2++;
}
void del(int x)
{
	if(num[x]==8)num8--;
	if(num[x]==6)num6--;
	if(num[x]==4)num4--;
	if(num[x]==2)num2--;
	num[x]--;
}
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);add(x);}
	scanf("%d",&q);
	rep(i,q)
	{
		char s[2];int x;
		scanf("%s%d",s,&x);
		if(s[0]=='+')add(x);else del(x);
		if((num8)||(num6&&num2>1)||(num4>=2)||(num4&&num2>2))puts("YES");
		else puts("NO");
	}
	return 0;
}