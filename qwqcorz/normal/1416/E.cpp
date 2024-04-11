#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void BackInBlack()
{
	int zero=0,two=-1;
	#define f(x) ((x-B)*A)
	struct node
	{
		set<int>S;
		int l,r,A,B;
		node(){l=A=1,r=B=0,S=set<int>();}
		void clear(){*this=node();}
		void fix(int L,int R)
		{
			L=f(L),R=f(R);
			if (L>R) swap(L,R);
			l=max(l,L),r=min(r,R);
			while (!S.empty()&&*S.begin()<L) S.erase(S.begin());
			while (!S.empty()&&*S.rbegin()>R) S.erase(*S.rbegin());
		}
		void insert(int L,int R){if (L>R) return;l=f(L),r=f(R);}
		void insert(int x){x=f(x);if (l<=x&&x<=r) return;S.insert(x);}
		bool count(int x){x=f(x);return l<=x&&x<=r||S.count(x);}
		bool empty(){return l>r&&S.empty();}
	}one;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (~two)
		{
			zero+=2;
			one.clear();
			if (two<a[i]) one.insert(a[i]-two);
			two=-1;
		}
		else if (!one.empty())
		{
			zero++;
			one.A=-one.A;
			one.B=a[i]-one.B;
			one.fix(1,a[i]-1);
		}
		else
		{
			one.A=1,one.B=0;
			one.insert(a[i]-min(a[i],a[i-1])+1,a[i]-1);
		}
		if (a[i]%2==0)
		{
			int x=a[i]/2;
			if (one.count(x)) two=x;
						 else one.insert(x);
		}
/*
		print(zero,' '),print(two);
		print(one.A,','),print(one.B);
		print(one.l,' '),print(one.r,':');
		for (int i:one.S) print(i,' ');
		puts("");
//*/
	}
	int ans=zero;
	if (!one.empty()) ans=zero+1;
	if (~two) ans=zero+2;
	print(n*2-ans);
}

signed main()
{
	int T=read();
	while (T--) BackInBlack();
	
	return 0;
}