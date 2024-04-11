#include <iostream>
using namespace std;

#define SEG (1<<17)
#define MOD 1000000007
long long seg[2*SEG][2],up[2*SEG][2],l[2*SEG],r[2*SEG];
int A[2*SEG];

long long ar[2][2];
long long mat[2][2];
long long tmp[2][2];

void mult(long long m1[2][2],long long m2[2][2])
{
	tmp[0][0] = (m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])%MOD;
	tmp[0][1] = (m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1])%MOD;
	tmp[1][0] = (m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0])%MOD;
	tmp[1][1] = (m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1])%MOD;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			m1[i][j] = tmp[i][j];
}

int fib(long long n)
{
	if(n==0) return 0;
	n--;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			ar[i][j] = (i==j);
	if(n==0) return 1;
	int i = 31;
	while(!(n&(1LL<<i)))
		i--;
	for(;i>=0;i--)
	{
		mult(ar,ar);
		if(n&(1LL<<i))
			mult(ar,mat);
	}
	return ar[0][0];
}

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		l[i] = r[i] = i-SEG;
		seg[i][0] = fib(A[i-SEG]);
		seg[i][1] = fib(A[i-SEG]+1);
	}
	for(int i=SEG-1;i>=0;i--)
	{
		l[i] = l[2*i], r[i] = r[2*i+1];
		seg[i][0] = (seg[2*i][0]+seg[2*i+1][0])%MOD;
		seg[i][1] = (seg[2*i][1]+seg[2*i+1][1])%MOD;
	}
}

void addFib(long long a[2],long long b[2])
{
//	cout << "init: " << a[0] << ' ' << a[1] << '\n';
//	cout << "init: " << b[0] << ' ' << b[1] << '\n';
	long long c0 = (((a[0]+a[1])*b[0])+(a[0]*b[1]))%MOD;
	long long c1 = ((a[0]*b[0])+(a[1]*b[1]))%MOD;
	a[0] = c0, a[1] = c1;
//	cout << "fib: " << c0 << ' ' << c1 << '\n';
}

void push(int i)
{
	if(up[i][0])
	{
		if(i<SEG)
		{
			if(up[2*i][0])
				addFib(up[2*i],up[i]);
			else
				up[2*i][0] = up[i][0], up[2*i][1] = up[i][1];
			if(up[2*i+1][0])
				addFib(up[2*i+1],up[i]);
			else
				up[2*i+1][0] = up[i][0], up[2*i+1][1] = up[i][1];
		}
		long long tmp0 = seg[i][0];
		long long tmp1 = seg[i][1];
		seg[i][0] = (((long long)up[i][0])*tmp1 + ((long long)up[i][1])*tmp0)%MOD;
		seg[i][1] = (((long long)(up[i][0]+up[i][1]))*tmp1 + ((long long)up[i][0])*tmp0)%MOD;
		up[i][0] = up[i][1] = 0;
	}
}

int low,high;
void update(int i,long long x[2])
{
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		if(up[i][0])
			addFib(up[i],x);
		else
			up[i][0] = x[0], up[i][1] = x[1];
		push(i);
		return;
	}
	push(i);
	update(2*i,x);
	update(2*i+1,x);
	seg[i][0] = (seg[2*i][0]+seg[2*i+1][0])%MOD;
	seg[i][1] = (seg[2*i][1]+seg[2*i+1][1])%MOD;
}

long long getSum(int i)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i][0];
	return (getSum(2*i)+getSum(2*i+1))%MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	mat[0][0] = mat[0][1] = mat[1][0] = 1;
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++) cin >> A[i];
	init();
	int tp,x;
	long long a[2];
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> low >> high;
		low--,high--;
		if(tp==1)
		{
			cin >> x;
			a[0] = fib(x), a[1] = fib(x-1);
			update(1,a);
		}
		else
			cout << getSum(1) << '\n';
	}
}