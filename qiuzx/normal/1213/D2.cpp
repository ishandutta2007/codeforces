#include <bits/stdc++.h>
#define N 200010 
using namespace std;
int lst[N],plc[N];
int n,k,num,ans=1000000000;
vector<int> v;
int main(){
	int i,x,cnt;
	memset(lst,0,sizeof(lst));
	memset(plc,0,sizeof(plc));
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		x=v[i];
		cnt=0;
		while(x>=0)
		{
			plc[x]++;
			lst[x]+=cnt;
			if(plc[x]==k)
			{
				ans=min(ans,lst[x]);
			}
			cnt++;
			if(x==0)
			{
				break;
			}
			x/=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}