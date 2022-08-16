#include"stdio.h"
#include"queue"
#include"vector"
#include"algorithm"
using namespace std;
int timePerTeam[100][100];
vector<int> solved[100];
int main()
{
	freopen("input.txt", "rt", stdin); 
	freopen("output.txt", "wt", stdout);
	int n,t;
	scanf("%d%d",&n,&t);
	int a[n][2],b[n][2];
	for(int x=0;x<n;x++)	scanf("%d%d%d%d",&a[x][0],&b[x][0],&a[x][1],&b[x][1]);
	int m;
	scanf("%d",&m);
	char inp[m][1000];
	int time[m];
	queue<int> q;
	for(int x=0;x<m;x++)	scanf("%s%d",inp[x],&time[x]),q.push(x);
	int tp=t;
	for(int i=0;!q.empty();i++)
	{
		if(tp==0){tp=t;continue;}
		int chit=q.front();
		q.pop();
		int teamno=i%n,teamMember=(i/n)&1;
		int othermember=1-teamMember;
		int timetaken=max(1,time[chit]-a[teamno][teamMember]-b[teamno][othermember]-timePerTeam[chit][teamno]);
		if(timetaken<=tp)
		{
			solved[teamno].push_back(chit);
			i--;
			tp=tp-timetaken;
			continue;
		}
		else
		{
			timePerTeam[chit][teamno]+=tp;
			tp=t;
			q.push(chit);
		}
	}
	for(int x=0;x<n;x++)
	{
		printf("%u",solved[x].size());
		for(unsigned int y=0;y<solved[x].size();y++)
			printf(" %s",inp[solved[x][y]]);
		printf("\n");
	}
}