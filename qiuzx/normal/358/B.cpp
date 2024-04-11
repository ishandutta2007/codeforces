#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){
	int n,i,pos;
	string s[N],tran,ans;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		ans+="<3";
		ans+=s[i];
	}
	ans+="<3";
	cin>>tran;
	for(i=0;i<ans.size();i++)
	{
		pos=tran.find(ans[i]);
		if(pos==-1)
		{
			cout<<"no"<<endl;
			return 0;
		}
		tran=tran.substr(pos+1);
	}
	cout<<"yes"<<endl;
	return 0;
}