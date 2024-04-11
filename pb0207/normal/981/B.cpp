#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std; 

typedef long long ll;

const int N=1e5+1e3+7;

map<int,int>mx;

int n,a[N],x[N];

ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&x[i]),mx[a[i]]=max(mx[a[i]],x[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&x[i]),mx[a[i]]=max(mx[a[i]],x[i]);
	for(map<int,int>::iterator it=mx.begin();it!=mx.end();it++)
		ans+=(*it).second;
	printf("%lld",ans);
}