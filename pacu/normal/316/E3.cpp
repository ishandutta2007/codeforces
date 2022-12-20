#include <cstdio>
#include <iostream>
using namespace std;
#define MOD 1000000000
#define SEG (1<<18)

long long fib[SEG+1];
long long ps[SEG+1];

void calcFib()
{
	fib[0] = fib[1] = 1;
	for(int i=2;i<=SEG;i++)
		fib[i] = (fib[i-1]+fib[i-2])%MOD;
	ps[0] = 1;
	for(int i=1;i<=SEG;i++)
		ps[i] = (ps[i-1]+fib[i])%MOD;
}

long long F(long long i)
{
	if(i<0) return 0;
	return fib[i];
}

int A[200000];
int N,Q;

long long s[2*SEG],t[2*SEG],up[2*SEG];
int l[2*SEG],r[2*SEG],sz[2*SEG];

void push(int i)
{
	if(i<SEG)
	{
		up[(i<<1)] += up[i];
		up[(i<<1)+1] += up[i];
		up[(i<<1)] %= MOD;
		up[(i<<1)+1] %= MOD;
	}
	if(sz[i]>=1)
		s[i] = (s[i]+ps[sz[i]-1]*up[i])%MOD;
	if(sz[i]>=2)
		t[i] = (t[i]+ps[sz[i]-2]*up[i])%MOD;
	up[i] = 0;
}

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		s[i] = t[i] = 0;
		if((i-SEG)<N) s[i] = A[i-SEG];
		l[i] = r[i] = i-SEG;
		sz[i] = 1;
		up[i] = 0;
	}
	for(int i=SEG-1;i>0;i--)
	{
		s[i] = (s[(i<<1)] + F(sz[(i<<1)])*s[(i<<1)+1] + F(sz[(i<<1)]-1)*t[(i<<1)+1])%MOD;
		t[i] = (t[(i<<1)] + F(sz[(i<<1)]-1)*s[(i<<1)+1] + F(sz[(i<<1)]-2)*t[(i<<1)+1])%MOD;
		l[i] = l[(i<<1)];
		r[i] = r[(i<<1)+1];
		sz[i] = sz[i<<1]+sz[(i<<1)+1];
		up[i] = 0;
	}
}

void update(int i,int loc,int v)
{
	push(i);
	if((l[i]>loc)||(r[i]<loc)) return;
	if((l[i]>=loc)&&(r[i]<=loc))
	{
		s[i] = v;
		return;
	}
	update((i<<1),loc,v);
	update((i<<1)+1,loc,v);
	s[i] = (s[(i<<1)] + F(sz[(i<<1)])*s[(i<<1)+1] + F(sz[(i<<1)]-1)*t[(i<<1)+1])%MOD;
	t[i] = (t[(i<<1)] + F(sz[(i<<1)]-1)*s[(i<<1)+1] + F(sz[(i<<1)]-2)*t[(i<<1)+1])%MOD;
}

int low,high;

void inc(int i,int d)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] = d;
		push(i);
		return;
	}
	inc((i<<1),d);
	inc((i<<1)+1,d);
	s[i] = (s[(i<<1)] + F(sz[(i<<1)])*s[(i<<1)+1] + F(sz[(i<<1)]-1)*t[(i<<1)+1])%MOD;
	t[i] = (t[(i<<1)] + F(sz[(i<<1)]-1)*s[(i<<1)+1] + F(sz[(i<<1)]-2)*t[(i<<1)+1])%MOD;
}

void getSum(int i,long long &ss,long long &tt,long long &szz)
{
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		ss = tt = szz = 0;
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		push(i);
		ss = s[i];
		tt = t[i];
		szz = sz[i];
		return;
	}
	long long sa,ta,sza,sb,tb,szb;
	push(i);
	getSum((i<<1),sa,ta,sza);
	getSum((i<<1)+1,sb,tb,szb);
	if(sza==0 || szb==0)
	{
		ss = sa+sb;
		tt = ta+tb;
		szz = sza+szb;
		return;
	}
	ss = (sa+F(sza)*sb+F(sza-1)*tb)%MOD;
	tt = (ta+F(sza-1)*sb+F(sza-2)*tb)%MOD;
	szz = (sza+szb)%MOD;
	return;
}

int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	calcFib();
	init();
	int t,a,b,c;
	long long ss,tt,szz;
	long long ans;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d %d",&t,&a,&b);
		if(t==1)
		{
			update(1,a-1,b);
//			A[a-1] = b;
		}
		else if(t==2)
		{
			low = a-1;
			high = b-1;
			getSum(1,ss,tt,szz);
			ans = 0;
			printf("%I64d\n",ss);
//			for(int i=low;i<=high;i++)
//				ans = (ans+F(i-low)*A[i])%MOD;
//			printf("%I64d %I64d\n",ss,ans);
		}
		else if(t==3)
		{
			scanf("%d",&c);
			low = a-1;
			high = b-1;
			inc(1,c);
//			for(int i=low;i<=high;i++)
//				A[i] += c;
		}
	}
	return 0;
}