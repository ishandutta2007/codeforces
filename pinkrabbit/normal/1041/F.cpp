#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define LL long long
int n,m;
int a[300001],b[300001];
int Ans;
map<int,int> mp;
int main(){
	scanf("%d%*d",&n);
	F(i,1,n) scanf("%d",a+i);
	scanf("%d%*d",&m);
	F(i,1,m) scanf("%d",b+i);
	F(i,1,n) ++mp[a[i]];
	F(i,1,m) ++mp[b[i]];
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
		Ans=max(Ans,it->second);
	for(int j=1;j<=1e9;j<<=1){
		mp.clear();
		F(i,1,n) ++mp[a[i]%(j<<1)];
		F(i,1,m) ++mp[(b[i]+j)%(j<<1)];
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
			Ans=max(Ans,it->second);
	}
	printf("%d\n",Ans);
	return 0;
}