#include <bits/stdc++.h>
using namespace std;
long long T,n,m,k,cur,nxt;
bool flag;
vector<long long> t;
int main(){
	long long i,j,tem;
	cin>>T;
	while(T--)
	{
		flag=false;
		cin>>n>>m>>k;
		t.clear();
		for(i=0;i<n;i++)
		{
			cin>>j;
			t.push_back(j);
		}
		for(i=0;i+1<n;i++)
		{
			cur=t[i];
			nxt=t[i+1];
			if(nxt-cur<k)
			{
				tem=max((long long)0,nxt-k);
				m+=cur-tem;
			}
			else
			{
				if(m<(nxt-cur)-k)
				{
					flag=true;
					break;
				}
				else
				{
					m-=(nxt-cur)-k;
				}
			}
		}
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}