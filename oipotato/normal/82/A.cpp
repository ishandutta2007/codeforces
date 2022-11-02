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
string s[6]={"","Sheldon","Leonard","Penny","Rajesh","Howard"};
int main()
{
	int n;scanf("%d",&n);
	int now=5;
	for(;n>now;n-=now,now*=2);
	n=(n-1)/(now/5)+1;
	cout<<s[n]<<endl;
    return 0;
}