#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
int n;
char s[1010];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,n-1)if(s[i]!=s[i+1]){printf("YES\n%c%c\n",s[i],s[i+1]);return 0;}
    puts("NO");
	return 0;
}