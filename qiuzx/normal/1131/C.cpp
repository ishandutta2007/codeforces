#include <bits/stdc++.h>
using namespace std;
int main(){
	int place[105];
	priority_queue<int> line;
	int n,i,a,mid;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		line.push(a);
	}
	memset(place,-1,sizeof(place));
	mid=n/2;
	i=0;
	while(!line.empty())
	{
		a=line.top();
		line.pop();
		if(i%2==0)
		{
			place[mid+(i/2)]=a;
		}
		else
		{
			place[mid-((i/2)+1)]=a;
		}
		i++;
	}
	for(i=0;i<105;i++)
	{
		if(place[i]==-1)
		{
			continue;
		}
		else
		{
			cout<<place[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}