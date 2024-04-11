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
char s[500010];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int now=1;
	for(;now<=n&&s[now]!=91;now++);
	if(now>n){puts("-1");return 0;}
	for(;now<=n&&s[now]!=58;now++);
	if(now>n){puts("-1");return 0;}
	int l=now;
	now=n;
	for(;now>=1&&s[now]!=93;now--);
	if(!now){puts("-1");return 0;}
	for(;now>=1&&s[now]!=58;now--);
	if(!now){puts("-1");return 0;}
	int r=now;
	if(l>=r){puts("-1");return 0;}
	int cnt=0;
	for(int i=l+1;i<r;i++)if(s[i]==124)cnt++;
	printf("%d\n",cnt+4);
	return 0;
}