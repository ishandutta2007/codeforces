#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
bool vis[310];
int main()
{
	char s[1100];
	scanf("%s",s+1);
	int len=strlen(s+1),cnt=0;
	rep(i,len){if(!vis[s[i]])cnt++;vis[s[i]]=1;}
	puts(cnt&1?"IGNORE HIM!":"CHAT WITH HER!");
	return 0;
}