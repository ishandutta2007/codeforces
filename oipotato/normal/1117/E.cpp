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
char s[10010],ans[10010],q[3][10010],a[3][10010];
int pos[26][26][26],n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int x=0,y=0,z=0;
	rep(i,n)
	{
		q[0][i]=x+'a';q[1][i]=y+'a';q[2][i]=z+'a';
		pos[x][y][z]=i;
		z++;
		if(z==26)y++,z=0;
		if(y==26)x++,y=0;
	}
	rep(i,3)
	{
		printf("? %s\n",q[i-1]+1);
		fflush(stdout);
		scanf("%s",a[i-1]+1);
	}
	rep(i,n)ans[pos[a[0][i]-'a'][a[1][i]-'a'][a[2][i]-'a']]=s[i];
	printf("! %s\n",ans+1);
	fflush(stdout);
	return 0;
}