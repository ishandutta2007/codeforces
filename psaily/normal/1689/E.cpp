#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int fa[N], a[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
bool work(int n)
{
	iota(fa, fa+5000, 0);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=30;j++)
		{
			if(a[i]>>j&1)
			{
				int f1 = find(n+j+1), f2= find(i); 
				if(f1 != f2)
				{
					fa[f1] = f2;
				}
			}
		}
	int ans = 0;
	for(int i=1;i<=n;i++) if(find(i)==i) ans++;
	if(ans==1)return 1;
	return 0;
}
int main()
{
	int test;cin>>test;
	while(test--)
	{
		auto lowbit=[&](int x)
		{	
			return x&(-x);
		};
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int res=0,isf=0;
		for(int i=1;i<=n;i++) if(!a[i]) res ++, a[i] ++;
		if(work(n))
		{
			cout<<res<<"\n";
			for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
		} 
		else
		{
			isf=0;
			for(int i=1;i<=n;i++)
			{
				a[i]--;
				if(work(n)) {
					isf=1;
					break;
				}a[i]++;
			}
			if(!isf)
			{
			    for(int i=1;i<=n;i++)
				{   
				    a[i]++;
    				if(work(n))
    				{
    					isf=1;break;
    				} a[i]--;
				}
			}
			if(isf) {
				cout<<res+1<<"\n";
				for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
			}
			else
			{
				int maxv=0;
				for(int i=1;i<=n;i++)maxv=max(maxv,lowbit(a[i]));
				for(int i=1;i<=n;i++)
					if(lowbit(a[i])==maxv) {a[i]--; break;}
				for(int i=1;i<=n;i++)
					if(lowbit(a[i])==maxv) {a[i]++; break;}
				cout<<res+2<<"\n";
				for(int i=1;i<=n;i ++) cout<<a[i]<< " \n"[i==n];
			}
		}
	}	
	return 0;
}