#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
map<string,int>dic;
char s[40];
int n;
string get(int x)
{
	string a="";
	for(;x;x/=10)a+=x%10+'0';
	reverse(a.begin(),a.end());
	return a;
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%s",s);
		string a="";
		int len=strlen(s);
		rep(j,len)a+=s[j-1];
		if(dic.find(a)==dic.end()){puts("OK");dic[a]=1;continue;}
		else
		{
			int x=dic[a];dic[a]++;
			a+=get(x);
			for(auto c:a)putchar(c);puts("");
		}
	}
    return 0;
}