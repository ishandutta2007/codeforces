#include <bits/stdc++.h>
using namespace std;
struct node
{
	int y_begin,y_end;
 
};
map<int, list <node> > m;
map<int, map<int,int> > visited;
map<int,map<int,int> > dist;
int arr[]  = {1,1,1,-1,-1,-1,0,0};
int arr1[] = {1,-1,0,1,-1,0,1,-1};
int ans;
int steps;
int x_initial,x_final;
int y_initial,y_final;
struct node2
{
	int x,y;
 
};
int isvalid(int x,int y)
{
	if(x>=0 && y>=0 && x<=1000000000 && y<=1000000000 )
	{
		
		list<node>::iterator i = m[x].begin();
		for(;i!=m[x].end();i++)
		{
			if( (*i).y_begin<=y && (*i).y_end>=y )
			{
 
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	ans=0;
	steps=0;
	cin>>x_initial>>y_initial>>x_final>>y_final;
	int n;
	cin>>n;
	int a;
	node b;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>b.y_begin;
		cin>>b.y_end;
 
		m[a].push_back(b);
	}
 	node2 temp;
	temp.x=x_initial;
	temp.y=y_initial;
	queue<node2> Q;
 	visited[x_initial][y_initial]=1;
	dist[x_initial][y_initial]=0;
	Q.push(temp);
 	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
 
		for(int i=0;i<8;i++)
		{
			if(isvalid(temp.x+arr[i],temp.y+arr1[i]) && visited[temp.x+arr[i]][temp.y+arr1[i]]==0 )
			{
				node2 temp2;
				visited[temp.x+arr[i]][temp.y+arr1[i]]=1;
				dist[temp.x+arr[i]][temp.y+arr1[i]]=1+dist[temp.x][temp.y];
				temp2.x = temp.x+arr[i];
				temp2.y = temp.y+arr1[i];
				Q.push(temp2);
 
 
			}
		}
	}
 	if(dist[x_final][y_final]!=0)
	{
		cout<<dist[x_final][y_final]<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}	
}