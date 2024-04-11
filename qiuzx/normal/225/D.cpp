#include <bits/stdc++.h>
#define N 20
#define M 131100
#define F first
#define S second
using namespace std;
int n,m,k=0,mask=0,nm,conma,x,y,st,tx,ty,fx,fy;
char grid[N][N];
pair<int,int> npc[10],tem;
vector<pair<int,int> > vp,np;
queue<int> step,corx,cory,mk;
queue<vector<pair<int,int> > > qm;
bool book[N][N][M]={};
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]>'0'&&grid[i][j]<='9')
			{
				k++;
				npc[grid[i][j]-'0']=make_pair(i,j);
			}
			else if(grid[i][j]=='@')
			{
				fx=i;
				fy=j;
			}
		}
	}
	j=0;
	conma=(1<<(2*(k-1)))-1;
	for(i=2;i<=k;i++)
	{
		if(npc[i].F==npc[i-1].F)
		{
			if(npc[i].S>npc[i-1].S)
			{
				mask+=(1<<j);
			}
			else
			{
				mask+=(3<<j);
			}
		}
		else if(npc[i].F>npc[i-1].F)
		{
			mask+=(2<<j);
		}
		j+=2;
	}
	book[npc[1].F][npc[1].S][mask]=true;
	for(i=1;i<=k;i++)
	{
		vp.push_back(make_pair(npc[i].F,npc[i].S));
	}
	qm.push(vp);
	step.push(0);
	corx.push(npc[1].F);
	cory.push(npc[1].S);
	mk.push(mask);
	while(qm.size())
	{
		vp=qm.front();
		x=corx.front();
		y=cory.front();
		st=step.front();
		mask=mk.front();
		qm.pop();
		corx.pop();
		cory.pop();
		step.pop();
		mk.pop();
		if(x==fx&&y==fy)
		{
			cout<<st<<endl;
			return 0;
		}
		for(i=0;i<4;i++)
		{
			tx=x+dir[i][0];
			ty=y+dir[i][1];
			if(tx==fx&&ty==fy)
			{
				cout<<st+1<<endl;
				return 0;
			}
			if(tx<0||tx>=n||ty<0||ty>=m)
			{
				continue;
			}
			if(grid[tx][ty]=='#')
			{
				continue;
			}
			tem=make_pair(tx,ty);
			if(find(vp.begin(),vp.end(),tem)!=vp.end()&&vp[vp.size()-1]!=tem)
			{
				continue;
			}
			nm=mask<<2;
			nm+=i;
			nm&=conma;
			if(book[tx][ty][nm])
			{
				continue; 
			}
			book[tx][ty][nm]=true;
			np=vp;
			for(j=vp.size()-1;j>0;j--)
			{
				np[j]=vp[j-1];
			}
			np[0]=tem;
			qm.push(np);
			step.push(st+1);
			corx.push(tx);
			cory.push(ty);
			mk.push(nm);
		}
	}
	cout<<-1<<endl;
	return 0;
}