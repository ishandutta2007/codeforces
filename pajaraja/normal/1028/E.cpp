#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
long long b[MAXN],a[MAXN];
int n;
int prev(int x)
{
	if(x==0) return n-1;
	return x-1;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>b[i];
	int t=MAXN;
	for(int i=0;i<n;i++) if(b[i]>b[prev(i)]) t=i;
	if(t==MAXN) 
	{
		if(b[0]!=0) {cout<<"NO"; return 0;}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) cout<<1<<" ";
		return 0;
	}
	printf("YES\n");
	int cur=prev(t);
	a[t]=b[t];
	for(int i=MAXN;i<2*MAXN;i++) if(i%b[t]==b[cur]) {a[cur]=i; break;}
	cur=prev(cur);
	while(cur!=t)
	{
		a[cur]=a[(cur+1)%n]+b[cur];
		cur=prev(cur);
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}