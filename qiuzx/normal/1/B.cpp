#include <bits/stdc++.h>
#define N 100010
#define INF 10000010
using namespace std;
int main(){
	vector<string> aft;
	int n,i,j,k;
	long long col,row,p;
	string s,ans,temp;
	cin>>n;
	aft.clear();
	for(i=0;i<n;i++)
	{
		cin>>s;
		col=0;
		temp="";
		j=s.find("R");
		k=s.find("C");
		if(j!=0||k<=1||s[1]<'0'||s[1]>'9')
		{
			p=1;
			k=INF;
			for(char c='0';c<='9';c++)
			{
				int q=s.find(c);
				if(q!=-1)
					k=min(k,q);
			}
			ans="R";
			for(j=k;j<s.size();j++)
			{
				ans+=s[j];
			}
			ans+="C";
			for(j=k-1;j>=0;j--)
			{
				col+=(s[j]-'A'+1)*p;
				p*=26;
			}
			while(col!=0)
			{
				temp+=col%10+'0';
				col/=10;
			}
			reverse(temp.begin(),temp.end());
			ans+=temp;
		}
		else
		{
			for(j=k+1;j<s.size();j++)
			{
				col*=10;
				col+=s[j]-'0';
			}
			while(col!=0)
			{
				if(col%26==0)
				{
					temp+='Z';
					col/=26;
					col--;
				}
				else
				{
					temp+=col%26+'A'-1;
					col/=26;
				}
			}
			reverse(temp.begin(),temp.end());
			ans=temp;
			for(j=1;j<k;j++)
				ans+=s[j];
		}
		aft.push_back(ans);
	}
	for(i=0;i<aft.size();i++)
		cout<<aft[i]<<endl;
	return 0;
}