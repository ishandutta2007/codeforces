//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
struct BIT{
	ll val[N],sval[N];
	void init()
	{
		memset(val,0,sizeof(val));
		memset(sval,0,sizeof(sval));
		return;
	}
	void upd(int x,ll v)
	{
		ll v2=x*v;
		++x;
		while(x<N)
		{
			val[x]+=v;
			sval[x]+=v2;
			x+=x&(-x);
		}
		return;
	}
	ll qry1(int x)
	{
		ll ret=0;
		++x;
		while(x>0)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
	ll qry2(int x)
	{
		ll ret=0;
		++x;
		while(x>0)
		{
			ret+=sval[x];
			x-=x&(-x);
		}
		return ret;
	}
	ll query(int l,int r)
	{
		return (qry1(r)*(r+1)-qry2(r))-(qry1(l-1)*l-qry2(l-1));
	}
}bit[2];
ll a[N],v[N][2],ans=0;
int n,num[N],id[N][2],tp[N][2],lst1,lst2;
bool ok1[N];
int main(){
	int i,j;
	n=rint();
	for(i=0;i<n;++i)
	{
		a[i]=rint();
		num[i]=__builtin_popcountll(a[i]);
		ok1[num[i]]=true;
	}
	for(i=0;i<60;++i)
	{
		if(!ok1[i])
		{
			continue;
		}
		bit[0].init();
		bit[1].init();
		lst1=lst2=0;
		ll cur1,cur2,cur=0;
		for(j=0;j<n;++j)
		{
			cur1=cur2=j;
			while(lst1>0)
			{
				--lst1;
				if(v[lst1][0]>=a[j])
				{
					++lst1;
					break;
				}
				if(tp[lst1][0])
				{
					cur-=bit[1].query(id[lst1][0],cur1-1);
					bit[0].upd(id[lst1][0],-1);
					bit[0].upd(cur1,1);
				}
				cur1=id[lst1][0];
			}
			while(lst2>0)
			{
				--lst2;
				if(v[lst2][1]<=a[j])
				{
					++lst2;
					break;
				}
				if(tp[lst2][1])
				{
					cur-=bit[0].query(id[lst2][1],cur2-1);
					bit[1].upd(id[lst2][1],-1);
					bit[1].upd(cur2,1);
				}
				cur2=id[lst2][1];
			}
			id[lst1][0]=cur1;
			v[lst1][0]=a[j];
			tp[lst1++][0]=(num[j]==i);
			id[lst2][1]=cur2;
			v[lst2][1]=a[j];
			tp[lst2++][1]=(num[j]==i);
			if(num[j]==i)
			{
				cur+=bit[1].query(cur1,j);
				bit[0].upd(cur1,1);
				bit[0].upd(j+1,-1);
				cur+=bit[0].query(cur2,j);
				bit[1].upd(cur2,1);
				bit[1].upd(j+1,-1);
			}
			ans+=cur;
		}
	}
	cout<<ans<<endl;
	return 0;
}