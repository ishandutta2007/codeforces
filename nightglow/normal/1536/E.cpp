#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 100005

#define Mo 1000000007

using namespace std;

char c[N];

int power(int x,int y)
{
	int s = 1;
	for (;y;y>>=1,x=1ll*x*x%Mo) if (y&1) s=1ll*s*x%Mo;
	return s;
}

void Main()
{
	int n,m,s = 0;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c);
		for (int j = 0; j < m; ++j) s += c[j] == '#'; 
	}
	printf("%d\n",(power(2,s) - (s == n * m) + Mo) %Mo);
	
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main(); 
}