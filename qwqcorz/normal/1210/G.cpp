#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=3.5e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,a[N],l[N],r[N];
int check(int k)
{
	priority_queue<int>q1;
	priority_queue<int,vector<int>,greater<int>>q2;
	int tag1=-k,tag2=-k,ans=0;
	for (int i=1;i<=n+1;i++) q1.push(0),q2.push(0);
	for (int i=1;i<=n;i++)
	{
		tag1+=a[i]-r[i],tag2+=a[i]-l[i];
		if (q1.top()+tag1<=0&&0<=q2.top()+tag2)
		{
			q1.push(-tag1);
			q2.push(-tag2);
		}
		if (0<q1.top()+tag1)
		{
			ans+=q1.top()+tag1;
			q2.push(q1.top()+tag1-tag2);
			q1.pop();
			q1.push(-tag1);
			q1.push(-tag1);
		}
		if (q2.top()+tag2<0)
		{
			ans-=q2.top()+tag2;
			q1.push(q2.top()+tag2-tag1);
			q2.pop();
			q2.push(-tag2);
			q2.push(-tag2);
		}
	}
	for (int x=q1.top()+tag1;x>-k;q1.pop(),x=q1.top()+tag1) ans+=x+k;
	for (int x=q2.top()+tag2;x<-k;q2.pop(),x=q2.top()+tag2) ans+=-k-x;
	return ans;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),l[i]=read(),r[i]=read();
	int l=-N*N,r=N*N;
	while (l<r)
	{
		int mid=(l+r+N*N+1)/2-(N*N+1)/2;
		if (check(mid)<check(mid+1)) r=mid;
								else l=mid+1;
	}
	print(check(l));
	
	return 0;
}