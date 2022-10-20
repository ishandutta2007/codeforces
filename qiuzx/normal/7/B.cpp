#include <bits/stdc++.h>
#define N 110
using namespace std;
int t,m,mem[N],cnt=1;
string s;
void alloc(int n)
{
	int i,j;
	bool nul=true;
	for(i=0;i+n<=m;i++)
	{
		for(j=i;j<i+n;j++)
		{
			if(mem[j]!=0)
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			nul=false;
			break;
		}
	}
	if(nul)
	{
		cout<<"NULL"<<endl;
		return;
	}
	for(j=i;j<i+n;j++)
	{
		mem[j]=cnt;
	}
	cout<<cnt<<endl;
	cnt++;
	return;
}
void erase(int x)
{
	int i;
	bool ill=true;
	for(i=0;i<m;i++)
	{
		if(mem[i]==x)
		{
			ill=false;
			mem[i]=0;
		}
	}
	if(ill||x==0)
	{
		cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
	}
	return;
}
void defragment()
{
	int i,j,tem[N];
	memset(tem,0,sizeof(tem));
	for(i=0,j=0;i<m;i++)
	{
		if(mem[i]!=0)
		{
			tem[j]=mem[i];
			j++;
		}
	}
	for(i=0;i<m;i++)
	{
		mem[i]=tem[i];
	}
}
int main(){
	int n;
	cin>>t>>m;
	while(t--)
	{
		cin>>s;
		if(s=="alloc")
		{
			cin>>n;
			alloc(n);
		}
		else if(s=="erase")
		{
			cin>>n;
			erase(n);
		}
		else
		{
			defragment();
		}
	}
	return 0;
}