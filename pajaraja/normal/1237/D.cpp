#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int a[MAXN];
int main()
{
	multiset<int> s;
	int n,mx=0,mn=1000000007; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) mx=max(mx,a[i]);
	for(int i=0;i<n;i++) mn=min(mn,a[i]);
	if(mn*2>=mx) {for(int i=0;i<n;i++) cout<<-1<<" "; return 0;}
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(t==i) {s.insert(-a[i]); t=i+1;}
		while(true)
		{
			int k=-(*s.begin());
			if(2*a[t%n]>=k) {s.insert(-a[(t++)%n]);}
			else break;
		}
		cout<<t-i<<" ";
		s.erase(s.lower_bound(-a[i]));
	}
}