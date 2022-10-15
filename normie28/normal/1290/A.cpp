#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int n,m,k,i,j,a[3500],t,t1,maxx;
vector<int> all;
deque<int> st;
int main() {
	ios;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		all.clear();
		st.clear();
		maxx=0;
	cin>>n>>m>>k;
	for (i=0;i<n;i++)
	cin>>a[i];
	for (i=0;i+(n-m)<n;i++)
	all.push_back(max(a[i],a[i+n-m]));
	int len=0;
	
	if (int(all.size())-1-k>0) len=int(all.size())-1-k;
//	cout<<len<<' ';
	for (i=0;i+len<all.size();i++)
	{
//		cout<<i<<' ';
		int cur=1e9+1;
		for (j=0;j<=len;j++) if (all[i+j]<cur) cur=all[i+j];
		if (cur>maxx) maxx=cur;
	}
	cout<<maxx<<endl;
	}
}