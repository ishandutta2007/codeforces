#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int n,t,c,ans,nows,sl,nowo,to,tw,wf;

vector<int >spd;

int main()
{
	cin>>n;
	tw=0x7fffffff;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t==1||t==3)
			cin>>c;
		if(t==1)
		{
			nows=c;
			while(!spd.empty()&& c>spd.back())
                spd.pop_back(),ans++;
		}
		if(t==2)
			to=1;
		if(t==3)
		{
			spd.push_back(c);
            while(!spd.empty()&&nows>spd.back())
                spd.pop_back(),ans++;
        }
		if(t==4)
			nowo=0;
		if(t==5)
			spd.clear();
		if(t==6)
			nowo++;
		if(to&&nowo)
			ans+=nowo,nowo=0;
		to=0;
	}
	cout<<ans;
}