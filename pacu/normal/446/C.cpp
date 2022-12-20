#include <iostream>
using namespace std;
#define SEG (1<<19)
#define MOD 1000000009

long long fib[300005];
long long ps[300005];

void calcFib()
{
	fib[0] = 0, fib[1] = 1;
	ps[0] = 0, ps[1] = 1;
	for(int i=2;i<=300004;i++)
	{
		fib[i] = (fib[i-2]+fib[i-1])%MOD;
		ps[i] = (ps[i-1]+fib[i])%MOD;
	}
}

long long seg[2*SEG],l[2*SEG],r[2*SEG],up[2*SEG][2],A[SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = A[i-SEG];
		l[i] = r[i] = i-SEG;
		up[i][0] = up[i][1] = 0;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = (seg[2*i]+seg[2*i+1])%MOD;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		up[i][0] = up[i][1] = 0;
	}
}

void push(int i)
{
	seg[i] = (seg[i] + up[i][0]*ps[r[i]-l[i]] + up[i][1]*ps[r[i]+1-l[i]])%MOD;
	if(i < SEG)
	{
		up[2*i][0] = (up[2*i][0] + up[i][0])%MOD;
		up[2*i][1] = (up[2*i][1] + up[i][1])%MOD;
		up[2*i+1][0] = (up[2*i+1][0] + up[i][0]*fib[l[2*i+1]-l[i]-1]+up[i][1]*fib[l[2*i+1]-l[i]])%MOD;
		up[2*i+1][1] = (up[2*i+1][1] + up[i][0]*fib[l[2*i+1]-l[i]]+up[i][1]*fib[l[2*i+1]-l[i]+1])%MOD;
	}
	up[i][0] = up[i][1] = 0;
}

int low,high;
void add(int i,long long n0,long long n1)
{
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		//cout << l[i] << ' ' << r[i] << ": " << n0 << ',' << n1 << '\n';
		up[i][0] = (up[i][0]+n0*fib[max(0LL,l[i]-low-1)] + n1*fib[l[i]-low])%MOD, up[i][1] = (up[i][1]+n0*fib[l[i]-low]+n1*fib[l[i]-low+1])%MOD;
		//cout << seg[i] << '\n';
		push(i);
		//cout << seg[i] << '\n';
		return;
	}
	push(i);
	add(2*i,n0,n1);
	add(2*i+1,n0,n1);
	seg[i] = (seg[2*i] + seg[2*i+1])%MOD;
}

long long getSum(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high))
	{
		push(i);
		return seg[i];
	}
	push(i);
	return (getSum(2*i)+getSum(2*i+1))%MOD;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	calcFib();
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++) cin >> A[i];
	init();
	int tp,l,r;
	for(int i=0;i<M;i++)
	{
		cin >> tp >> l >> r;
		l--,r--;
		if(tp==1)
		{
			low = l, high = r;
			add(1,0,1);
		}
		else
		{
			low = l, high = r;
			cout << getSum(1) << '\n';
		}
	}
}