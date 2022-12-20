#include <iostream>
using namespace std;
#define MOD 1000000000

int fib[100001];

void calcFib()
{
	fib[0] = fib[1] = 1;
	for(int i=2;i<=100000;i++)
		fib[i] = (fib[i-1]+fib[i-2])%MOD;
}

long long F(int i)
{
	if(i<0) return 0;
	return fib[i];
}

int A[100000];
int N,Q;

#define SEG (1<<18)

long long s[2*SEG],t[2*SEG];
int l[2*SEG],r[2*SEG],sz[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		s[i] = t[i] = 0;
		if((i-SEG)<N) s[i] = A[i-SEG];
		l[i] = r[i] = i-SEG;
		sz[i] = 1;
	}
	for(int i=SEG-1;i>0;i--)
	{
		s[i] = (s[2*i] + F(sz[2*i])*s[2*i+1] + F(sz[2*i]-1)*t[2*i+1])%MOD;
		t[i] = (t[2*i] + F(sz[2*i]-1)*s[2*i+1] + F(sz[2*i]-2)*t[2*i+1])%MOD;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		sz[i] = 2*sz[2*i];
	}
}

void update(int i,int v)
{
	i += SEG;
	s[i] = v;
	for(i/=2;i>0;i/=2)
	{
		s[i] = (s[2*i] + F(sz[2*i])*s[2*i+1] + F(sz[2*i]-1)*t[2*i+1])%MOD;
		t[i] = (t[2*i] + F(sz[2*i]-1)*s[2*i+1] + F(sz[2*i]-2)*t[2*i+1])%MOD;
	}
}

void getSum(int i,int low,int high,int &ss,int &tt,int &szz)
{
	if((l[i]>high)||(r[i]<low))
	{
		ss = tt = szz = 0;
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		ss = s[i];
		tt = t[i];
		szz = sz[i];
		return;
	}
	int sa,ta,sza,sb,tb,szb;
	getSum(2*i,low,high,sa,ta,sza);
	getSum(2*i+1,low,high,sb,tb,szb);
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
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> A[i];
	calcFib();
	init();
	int t,a,b,ss,tt,szz;
	for(int i=0;i<Q;i++)
	{
		cin >> t >> a >> b;
		if(t==1)
			update(a-1,b);
		else if(t==2)
		{
			getSum(1,a-1,b-1,ss,tt,szz);
			cout << ss << "\n";
		}
	}
	return 0;
}