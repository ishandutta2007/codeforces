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
int main()
{
	int n;
	scanf("%d",&n);
	int a=0,b=0;
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(x==25)a++;
		else if(x==50)b++,a--;
		else
		{
			if(b)a--,b--;else a-=3;
		}
		if(a<0||b<0){puts("NO");return 0;}
	}
	puts("YES");
    return 0;
}