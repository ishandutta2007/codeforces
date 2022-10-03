#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 200005
#define ll long long
#define mod 998244353
int n;
int a[MN],b[MN],c[MN];
map<int,int>mp;
int cc;
void ad(int x){if(mp[x]==0)++cc;++mp[x];}
void su(int x){--mp[x];if(mp[x]==0)--cc;}
void ans(int v){F(i,1,n)if(b[i]==v){printf("%d\n",i);break;}}
int main(){
	scanf("%d",&n);
	if(n<=3)return puts("1"),0;
	F(i,1,n)scanf("%d",a+i),b[i]=a[i];
	sort(a+1,a+n+1);
	F(i,1,n-1)c[i]=a[i+1]-a[i];
	F(i,1,n-1)ad(c[i]);
	F(i,1,n){
		if(i==1){
			su(c[1]);
			if(cc==1)return ans(a[1]),0;
			ad(c[1]);
		}
		else if(i==n){
			su(c[n-1]);
			if(cc==1)return ans(a[n]),0;
			ad(c[n-1]);
		}
		else{
			su(c[i-1]),su(c[i]),ad(c[i-1]+c[i]);
			if(cc==1)return ans(a[i]),0;
			su(c[i-1]+c[i]),ad(c[i]),ad(c[i-1]);
		}
	}
	puts("-1");
	return 0;
}