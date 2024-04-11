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
char s[]="qwertyuiopasdfghjkl;zxcvbnm,./";
int main()
{
	char t[10];
	scanf("%s",t);
	int del;
	if(t[0]=='R')del=-1;else del=1;
	char st[110];
	scanf("%s",st+1);int len=strlen(st+1);
	int f=strlen(s);
	rep(i,len)
	{
		int pos;
		for(int j=0;j<f;j++)if(s[j]==st[i]){pos=j;break;}
		putchar(s[pos+del]);
	}
	puts("");
    return 0;
}