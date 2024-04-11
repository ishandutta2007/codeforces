#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205*6;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool c[N];
vector<int>a;

signed main()
{
	int n=read();
	for (int i=1;i<=n*3;i++) c[read()]=1;
	for (int i=1;i<=n*6;i++) a.push_back(i);
	for (int k=1;k<=n*2;k++)
	{
		bool flag=0;
		int n=a.size(),zdy=c[a[0]]!=c[a[1]];
		for (int i=0;i<n-2;i++)
		{
			if (i%3!=1&&c[a[i+1]]!=c[a[i+2]]) zdy=1;
			if (c[a[i]]==k%2&&c[a[i+1]]==k%2&&c[a[i+2]]==k%2&&zdy)
			{
				print(a[i],' '),print(a[i+1],' '),print(a[i+2]);
				a.erase(a.begin()+i,a.begin()+i+3);
				flag=1;
				break;
			}
		}
		if (flag) continue;
		for (int i=0;i<n-2;i++) if (c[a[i]]==k%2&&c[a[i+1]]==k%2&&c[a[i+2]]==k%2)
		{
			print(a[i],' '),print(a[i+1],' '),print(a[i+2]);
			a.erase(a.begin()+i,a.begin()+i+3);
			flag=1;
			break;
		}
		assert(flag);
	}
	
	return 0;
}