#include<bits/stdc++.h>
#define MAXN 999999
using namespace std;

const int M=1005;
int n,a,b,x,t[M],minn=MAXN;

int main()
{
	cin>>n>>x;
	for (int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if (a>b)
			swap(a,b);
		for (int j=a;j<=b;j++)
			t[j]++;
	}
	for (int i=0;i<M;i++)
		if (t[i]==n)
			minn=min(minn,abs(i-x));
	if (minn==MAXN)
		cout<<-1;
	else
		cout<<minn;
	return 0;
}