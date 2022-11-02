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
map<string,int>num;
int main()
{
	int T;
	int mx=0;
	for(scanf("%d",&T);T--;)
	{
		string s;
		cin>>s;
		num[s]++;mx=max(mx,num[s]);
	}
	for(const auto&i:num)if(i.second==mx)cout<<i.first;
    return 0;
}