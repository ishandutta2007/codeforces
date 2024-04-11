#include <bits/stdc++.h>
#define N 2750140
using namespace std;
int n,x,facn[N]={},num[N]={},cnt=1;
vector<int> b;
void findfac()
{
	int i,j;
	for(i=2;i*i<N;i++)
	{
		if(facn[i]<=0)
		{
			facn[i]=-cnt;
			cnt++;
			for(j=i*2;j<N;j+=i)
			{
				facn[j]=max(facn[j],j/i);
			}
		}
	}
	for(;i<N;i++)
	{
		if(facn[i]==0)
		{
			facn[i]=-cnt;
			cnt++;
		}
	}
}
int main(){
	int i,pos;
	findfac();
	cin>>n;
	b.clear();
	for(i=0;i<2*n;i++)
	{
		cin>>x;
		num[x]++;
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	for(i=0;i<b.size();i++)
	{
		x=b[i];
		if(num[x]<=0)
		{
			continue;
		}
		num[x]--;
		if(facn[x]<=0)
		{
			cout<<-facn[x]<<" ";
		}
		else
		{
			cout<<x<<" ";
		}
		num[abs(facn[x])]--;
	}
	cout<<endl;
	return 0;
}