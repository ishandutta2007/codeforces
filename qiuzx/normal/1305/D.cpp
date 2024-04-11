#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
int n,ttn[N],nml,fa[N];
vector<int> vt[N];
queue<int> q;
int main(){
	int i,x,y,a;
	memset(ttn,0,sizeof(ttn));
	cin>>n;
	nml=n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
		ttn[x]++;
		ttn[y]++;
	}
	for(i=0;i<n;i++)
	{
		if(ttn[i]==1)
		{
			q.push(i);
		}
	}
	while(nml>1)	
	{
		x=q.front();
		q.pop();
		y=q.front();
		q.pop(); 
		cout<<"? "<<x+1<<" "<<y+1<<endl;
		fflush(stdout);
		cin>>a;
		a--;
		if(a==x)
		{
			cout<<"! "<<x+1<<endl;
			return 0;
		}
		if(a==y)
		{
			cout<<"! "<<y+1<<endl;
			return 0;
		}
		a=vt[x][0];
		vt[a].erase(find(vt[a].begin(),vt[a].end(),x));
		ttn[a]--;
		vt[x].erase(vt[x].begin());
		if(ttn[a]==1)
		{
			q.push(a);
		}
		a=vt[y][0];
		vt[a].erase(find(vt[a].begin(),vt[a].end(),y));
		ttn[a]--;
		vt[y].erase(vt[y].begin());
		if(ttn[a]==1)
		{
			q.push(a);
		}
		nml-=2;
	}
	x=q.front();
	cout<<"! "<<x+1<<endl;
	return 0;
}