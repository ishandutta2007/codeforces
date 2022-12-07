#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[20000010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+2*n+1);
	long long ans=(num[n]-num[1])*1ll*(num[2*n]-num[n+1]);
	for(int i=1;i<=n+1;i++)
		ans=min(ans,(num[n+i-1]-num[i])*1ll*(num[2*n]-num[1]));
	cout<<ans;
}