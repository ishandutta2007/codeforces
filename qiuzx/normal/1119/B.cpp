#include <bits/stdc++.h>
#define N 1010
using namespace std;
int main(){
	vector<long long> hei,temp;
	long long n,h,a,i,j,sum=0;
	cin>>n>>h;
	for(i=0;i<n;i++)
	{
		cin>>a;
		hei.push_back(a);
	}
	temp=hei;
	for(i=n;i>0;i--)
	{
		hei=temp;
		sort(hei.begin(),hei.end());
		reverse(hei.begin(),hei.end());
		sum=0;
		for(j=0;j<hei.size();j+=2)
		{
			if(sum>h)
				break;
			if(hei.size()-j==1)
			{
				sum+=hei[j];
				break;
			}
			else
				sum+=max(hei[j],hei[j+1]);
		}
		temp.erase(temp.end()-1);
		hei=temp;
		if(sum>h)
			continue;
		else
			break;
	}
	cout<<i<<endl;
	return 0;
}