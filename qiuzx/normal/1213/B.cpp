#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,i,x,lst,ans;
	vector<int> v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		lst=1000000000;
		v.clear();
		for(i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		for(i=v.size()-1;i>=0;i--)
		{
			if(v[i]>lst)
			{
				ans++;
			}
			else
			{
				lst=v[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}