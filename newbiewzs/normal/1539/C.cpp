#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LI;

const int N=200005;
int n,ans;
LI K,X;
LI a[N];
vector<LI> cho;
int main()
{
	cin>>n>>K>>X;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]>X)ans++,cho.push_back((a[i]-a[i-1]-1)/X);
	sort(cho.begin(),cho.end());
	for(int i=0;i<(int)cho.size();i++)
		if(K>=cho[i])K-=cho[i],ans--;
		else break;
	printf("%d\n",ans);
	return 0;
}