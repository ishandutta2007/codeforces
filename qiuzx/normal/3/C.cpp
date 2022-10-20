#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,p1_num=0,p2_num=0;
	char c[3][3],dia[3];
	bool full=true;
	int p1_won=0,p2_won=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='.')
			{
				full=false;
			}
			else if(c[i][j]=='X')
			{
				p1_num++;
			}
			else if(c[i][j]=='0')
			{
				p2_num++;
			}
		}
	}
	
	j=0;
	for(i=0;i<3;i++)
	{
		dia[j]=c[i][i];
		j++;
	}
	if(dia[0]==dia[1]&&dia[1]==dia[2]&&dia[2]=='X')
		p1_won++;
	else if(dia[0]==dia[1]&&dia[1]==dia[2]&&dia[2]=='0')
		p2_won++;
	j=2;
	for(i=0;i<3;i++)
	{
		dia[j]=c[i][j];
		j--;
	}
	if(dia[0]==dia[1]&&dia[1]==dia[2]&&dia[2]=='X')
		p1_won++;
	else if(dia[0]==dia[1]&&dia[1]==dia[2]&&dia[2]=='0')
		p2_won++;
	for(i=0;i<3;i++)
	{
		if(c[i][0]==c[i][1]&&c[i][1]==c[i][2]&&c[i][2]=='X')
			p1_won++;
		else if(c[i][0]==c[i][1]&&c[i][1]==c[i][2]&&c[i][2]=='0')
			p2_won++;
		else if(c[0][i]==c[1][i]&&c[1][i]==c[2][i]&&c[2][i]=='X')
			p1_won++;
		else if(c[0][i]==c[1][i]&&c[1][i]==c[2][i]&&c[2][i]=='0')
			p2_won++;
	}
	
	if((p1_won&&p2_won)||(p1_num-p2_num>=2||p2_num>p1_num)||(p1_num==p2_num&&p1_won>0)||(p1_num-p2_num>=1&&p2_won>0))
		cout<<"illegal"<<endl;
	else if(p1_won)
		cout<<"the first player won"<<endl;
	else if(p2_won)
		cout<<"the second player won"<<endl;
	else if(!p1_won&&!p2_won&&full)
		cout<<"draw"<<endl;
	else if(p1_num==p2_num)
		cout<<"first"<<endl;
	else if(p2_num==p1_num-1)
		cout<<"second"<<endl;
	return 0;
}