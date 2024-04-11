#include <bits/stdc++.h>
#define N 20
using namespace std;
string grid[N][N];
int n,m;
//int px1=-1,py1=-1,px2=-1,py2=-1;
bool ch(int x1,int y1,int x2,int y2)
{
	if(x2<x1+3&&y2<y1+3)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int get(char c)
{
	if(c=='A')
	{
		return(1);
	}
	if(c=='T')
	{
		return(10);
	}
	if(c=='J')
	{
		return(11);
	}
	if(c=='Q')
	{
		return(12);
	}
	if(c=='K')
	{
		return(13);
	}
	return(c-'0');
}
/************************************CHECK***************************************/
void check(string j1,string j2)
{
	string ng[N][N],last;
	int i,j,k,l,x1,y1,x2,y2,num;
	bool all,nsa,can[N][N],book[15];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(grid[i][j]=="J1")
			{
				ng[i][j]=j1;
			}
			else if(grid[i][j]=="J2")
			{
				ng[i][j]=j2;
			}
			else
			{
				ng[i][j]=grid[i][j];
			}
		}
	}
	memset(can,true,sizeof(can));
	for(k=0;k<=n-3;k++)
	{
		for(l=0;l<=m-3;l++)
		{
			all=true;
			nsa=true;
			memset(book,0,sizeof(book));
			last="";
			for(i=k;i<k+3;i++)
			{
				for(j=l;j<l+3;j++)
				{
					num=get(ng[i][j][0]);
					if(book[num])
					{
						nsa=false;
					}
					book[num]=true;
					if(last==""||last[1]==ng[i][j][1])
					{
						last=ng[i][j];
					}
					else
					{
						all=false;
					}
					if(!all&&!nsa)
					{
						can[k][l]=false;
						break;
					}
				}
				if(!can[k][l])
				{
					break;
				}
			}
			if(!can[k][l])
			{
				continue;
			}
		}
	}
	for(x1=0;x1<=n-3;x1++)
	{
		for(y1=0;y1<=m-3;y1++)
		{
			if(!can[x1][y1])
			{
				continue;
			}
			for(x2=0;x2<=n-3;x2++)
			{
				for(y2=0;y2<=m-3;y2++)
				{
					if(!can[x2][y2]||ch(x1,y1,x2,y2))
					{
						continue;
					}
					cout<<"Solution exists."<<endl;
					if(j1!="")
					{
						cout<<"Replace J1 with "<<j1;
					}
					if(j2!="")
					{
						if(j1=="")
							cout<<"Replace J2 with "<<j2;
						else
							cout<<" and J2 with "<<j2;
					}
					if(j1==""&&j2=="")
					{
						cout<<"There are no jokers";
					}
					cout<<"."<<endl;
					cout<<"Put the first square to ("<<x1+1<<", "<<y1+1<<")."<<endl;
					cout<<"Put the second square to ("<<x2+1<<", "<<y2+1<<")."<<endl;
					exit(0);
				}
			}
		}
	}
}
/*************************************MAIN************************************/
int main(){
	string reg[13]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
	string flc[4]={"C","D","H","S"};
	string ans="",tem;
	int i,j;
	vector<string> ss;
	bool j1=false,j2=false;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>grid[i][j];
			ans+=grid[i][j];
			if(grid[i][j]=="J1")
			{
				j1=true;
				//px1=i;
				//py1=j;
			}
			else if(grid[i][j]=="J2")
			{
				j2=true;
				//px2=i;
				//py2=j;
			}
		}
	}
	if(n<6&&m<6)
	{
		cout<<"No solution."<<endl;
		return 0;
	}
	for(i=0;i<13;i++)
	{
		for(j=0;j<4;j++)
		{
			tem=reg[i]+flc[j];
			if(ans.find(tem)==-1)
			{
				ss.push_back(tem);
			}
		}
	}
	if(!j1&&!j2)
	{
		check("","");
	}
	else if(j1&&j2)
	{
		for(i=0;i<ss.size();i++)
		{
			for(j=0;j<ss.size();j++)
			{
				if(j==i)
				{
					continue;
				}
				check(ss[i],ss[j]);
			}
		}
	}
	else if(j1)
	{
		for(i=0;i<ss.size();i++)
		{
			check(ss[i],"");
		}
	}
	else
	{
		for(i=0;i<ss.size();i++)
		{
			check("",ss[i]);
		}
	}
	cout<<"No solution."<<endl;
	return 0;
}