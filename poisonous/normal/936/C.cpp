#include<bits/stdc++.h>
using namespace std;
string s1,s2,tmp;
int a1[200];
vector<int> ans;
int main()
{
	int n;
	cin>>n;
	cin>>s2>>s1;
	for(int i=0;i<n;i++)
		a1[s1[i]]++,a1[s2[i]]--;
	for(int i=1;i<=150;i++)
		if(a1[i]!=0)
		{
			cout<<"-1";
			return 0;
		}
	int now[2],t=0;
	now[0]=now[1]=(n+1)/2-1;
	for(int i=0;i<n;i++)
	{
		int k=-1;
		//cout<<now[t]<<' '<<s1[now[t]]<<endl;
		for(int j=i;j<n;j++)
			if(s2[j]==s1[now[t]])
				k=j;
		ans.push_back(n-(k));
		tmp=s2.substr(k);
		reverse(tmp.begin(),tmp.end());
		s2=tmp+s2.substr(0,k);	
		ans.push_back(k-i);
		//cout<<n-k+i<<endl;
		//cout<<s2<<endl;
		if(n-k+i<n)
		{
			tmp=s2.substr(n-k+i);
			reverse(tmp.begin(),tmp.end());
			s2=tmp+s2.substr(0,n-k+i);	
		}
		ans.push_back(i+1);
		//cout<<s2<<endl;
		//cout<<n-i-1<<endl;
		if(n-i-1<n)
		{
			tmp=s2.substr(n-i-1);
			reverse(tmp.begin(),tmp.end());
			s2=tmp+s2.substr(0,n-i-1);	
		}
		//cout<<s2<<endl;
		t^=1;
		if(t==1)
			now[t]++;
		else
			now[t]--;
	}
	if(n%2==1)
		ans.push_back(n);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<' ';
}