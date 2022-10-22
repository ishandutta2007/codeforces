#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll; 

const int N=1e5+1e3+7;

int a[N],n,k;

struct node{
	int l,r;
};

queue<node> q;

int main() 
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		a[i]=i+1; 
	if(!(k&1))
	{
		puts("-1");
		return 0;
	}
	int ans=1;
	q.push(node{0,n});
	while(!q.empty()) 
	{
		if(ans>=k)
			break;
		int l=q.front().l;
		int r=q.front().r;
		q.pop();
		if(l+1==r)
			continue;
		int mid=(l+r)>>1;
		swap(a[mid],a[mid-1]);
		ans+=2;
		q.push(node{l,mid});
		q.push(node{mid,r});
	}
	if(ans<k) 
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}