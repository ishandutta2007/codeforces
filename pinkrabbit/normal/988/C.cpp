#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n,m,k;
int a[200001];
map<int,pair<int,int> > mp;
int main(){
	scanf("%d",&k);
	F(i,1,k){
		scanf("%d",&n);
		int Sum=0;
		F(j,1,n){
			scanf("%d",a+j), Sum+=a[j];
		}
		F(j,1,n){
			if(mp.count(Sum-a[j])){
				puts("YES");
				printf("%d %d\n",i,j);
				printf("%d %d\n",mp[Sum-a[j]].first,mp[Sum-a[j]].second);
				return 0;
			}
		}
		F(j,1,n) mp[Sum-a[j]]=make_pair(i,j);
	}
	return 0*puts("NO");
}