#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=2010;
int p[N],n,k;
char a[N],b[N];
vector<pair<int,int>>ansa,ansb;
void rev(int l,int r,int ltyp,int rtyp,vector<pair<int,int>>&ans)
{
	int now=0;
	for(int i=0;i<l;i++)now+=p[i]+1;
	int L=now+(!ltyp)*p[l]+1;
	for(int i=l;i<r;i++)now+=p[i]+1;
	int R=now+rtyp*p[r];
	ans.pb(mp(L,R));
	if(l<r-1)reverse(p+l+1,p+r);
	if(ltyp&&rtyp)swap(p[l],p[r]);
	else if(ltyp)p[r]+=p[l],p[l]=0;
	else if(rtyp)p[l]+=p[r],p[r]=0;
}
void work(char a[],vector<pair<int,int>>&ans)
{
	ans.clear();
	int cnt=0,now=0;
	rep(i,n)if(a[i]=='0')now++;else p[cnt++]=now,now=0;
	p[cnt]=now;
	for(int i=cnt;i>k+1;i--)if(p[i])rev(i-k,i,0,1,ans);
	rep(i,k+1)rev(0,k,0,1,ans),rev(1,k+1,1,k&1,ans);
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",a+1);
		scanf("%s",b+1);
		int cnt1=0,cnt2=0;
		rep(i,n)cnt1+=a[i]-'0';
		rep(i,n)cnt2+=b[i]-'0';
		if(cnt1!=cnt2){puts("-1");continue;}
		if(!k||k>cnt1)
		{
			bool flag=1;
			rep(i,n)if(a[i]!=b[i]){flag=0;break;}
			puts(flag?"0":"-1");
			continue;
		}
		if(k==cnt1)
		{
			int l=-1,r;
			rep(i,n)if(a[i]=='1'){if(l==-1)l=i;r=i;}
			int l1=l,r1=r;
			l=-1;
			rep(i,n)if(b[i]=='1'){if(l==-1)l=i;r=i;}
			if(r1-l1+1!=r-l+1){puts("-1");continue;}
			bool flag=1;
			for(int i=l1;i<=r1;i++)if(a[i]!=b[l+i-l1]){flag=0;break;}
			if(flag){printf("2\n%d %d\n%d %d\n",min(l1,l),max(r1,r),l,r);continue;}
			reverse(b+l,b+r+1);
			flag=1;
			for(int i=l1;i<=r1;i++)if(a[i]!=b[l+i-l1]){flag=0;break;}
			if(flag)printf("1\n%d %d\n",min(l1,l),max(r1,r));
			else puts("-1");
			continue;
		}
		work(a,ansa);
		work(b,ansb);
		reverse(ansb.begin(),ansb.end());
		for(auto i:ansa)reverse(a+i.first,a+i.second+1);
		for(auto i:ansb)reverse(a+i.first,a+i.second+1);
		bool flag=1;
		rep(i,n)if(a[i]!=b[i]){flag=0;break;}
		if(!flag){puts("-1");continue;}
		printf("%d\n",(int)ansa.size()+(int)ansb.size());
		for(auto i:ansa)printf("%d %d\n",i.first,i.second);
		for(auto i:ansb)printf("%d %d\n",i.first,i.second);
	}
    return 0;
}