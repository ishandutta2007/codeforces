#include <bits/stdc++.h>
#define INF 100010
using namespace std;
char grid[25][25];
int x,y;
int com(int a,int b)
{
	set<string> all;
	string beg,beg1,beg2,beg3;
	int t,i,j,m,n,s=0;
	for(i=0;i<x;i+=a)
		for(j=0;j<y;j+=b)
		{
			beg="";
			for(m=i;m<i+a;m++)
				for(n=j;n<j+b;n++)
					beg+=grid[m][n];
			all.insert(beg);
			if(a==b)
			{
				beg1="";
				for(n=j;n<j+b;n++)
					for(m=i+a-1;m>=i;m--)
						beg1+=grid[m][n];
				all.insert(beg1);
			}
			beg2="";
			for(m=i+a-1;m>=i;m--)
				for(n=j+b-1;n>=j;n--)
					beg2+=grid[m][n];
			all.insert(beg2);
			if(a==b)
			{
				beg3="";
				for(n=j+b-1;n>=j;n--)
					for(m=i;m<i+a;m++)
						beg3+=grid[m][n];
				all.insert(beg3);
			}
			//cout<<beg<<" "<<beg1<<" "<<beg2<<" "<<beg3<<endl;
			t=1;
			if(a==b)
			{
				if(beg1!=beg)
					t++;
				if(beg2!=beg1&&beg2!=beg)
					t++;
				if(beg3!=beg2&&beg3!=beg1&&beg3!=beg)
					t++;
			}
			else
			{
				if(beg2!=beg)
				{
					t++;
				}
			}
			if(all.size()-s<t)
				return 0;
			s=all.size();
		}
	return 1;
}
int main(){
	int a,b,i,j,num=0,minx,miny,minf=INF;
	cin>>x>>y;
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			cin>>grid[i][j];
	for(a=1;a<=x;a++)
		for(b=1;b<=y;b++)
			if(x%a==0&&y%b==0)
			{
				if(!com(a,b))
					continue;
				num++;
				//cout<<"***************************"<<endl;
				if(minf>a*b)
				{
					minx=a;
					miny=b;
					minf=a*b;
				}
			}
	if(minf==INF)
		cout<<"1"<<endl<<x<<" "<<y<<endl;
	else
		cout<<num<<endl<<minx<<" "<<miny<<endl;
	return 0;
}