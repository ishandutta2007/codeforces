#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int main()
{
	int n;
	scanf("%d",&n);
	int X=0,Y=0;
	rep(i,n)
	{
		char s[10];
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if(x>y)swap(x,y);
		if(s[0]=='+')X=max(X,x),Y=max(Y,y);
		else puts(X<=x&&Y<=y?"YES":"NO");
	}
	return 0;
}