# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>
# include <queue>
# include <map>

using namespace std;

set<int> norep;
map<int,int> rep;
int arr[100000];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	
	for(int i=0;i<N;i++)
		scanf("%d",arr+i);
	
	for(int i=0;i<K;i++)
	{
		if(rep.find(arr[i])!=rep.end())rep[arr[i]]++;
		else if(norep.find(arr[i])!=norep.end()){norep.erase(arr[i]);rep[arr[i]]=2;}
		else norep.insert(arr[i]);
	}
	
	if(norep.begin()==norep.end())printf("Nothing\n");
	else printf("%d\n",*norep.rbegin());
	
	for(int i=0;i+K<N;i++)
	{
		if(rep.find(arr[i])!=rep.end())
		{
			if(rep[arr[i]]==2)
			{
				rep.erase(arr[i]);
				norep.insert(arr[i]);
			}
			else rep[arr[i]]--;
		}
		else norep.erase(arr[i]);
		
		if(rep.find(arr[i+K])!=rep.end())rep[arr[i+K]]++;
		else if(norep.find(arr[i+K])!=norep.end()){norep.erase(arr[i+K]);rep[arr[i+K]]=2;}
		else norep.insert(arr[i+K]);
		
		if(norep.begin()==norep.end())printf("Nothing\n");
		else printf("%d\n",*norep.rbegin());
	}
	return 0;
}