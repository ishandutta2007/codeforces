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
map<string,string>dic;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,m)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()>s2.length())dic[s1]=s2;
		else dic[s1]=s1;
	}
	rep(i,n)
	{
		string s;
		cin>>s;
		cout<<dic[s]<<" \n"[i==n];
	}
    return 0;
}