#include <cstdio>
#include <algorithm>
using namespace std;

char s[2000001];
char t[2000001];
int N;
int cnt[2][2];

int main()
{
	scanf("%d",&N);
	scanf("%s",s);
	scanf("%s",t);
	for(int i=0;i<2*N;i++)
		cnt[s[i]=='1'][t[i]=='1']++;
	int cFirst = 0;
	int cSecond = 0;
	for(int i=0;i<N;i++)
	{
		if(cnt[1][1]) cnt[1][1]--, cFirst++;
		else if(cnt[1][0]) cnt[1][0]--, cFirst++;
		else if(cnt[0][1]) cnt[0][1]--;
		else cnt[0][0]--;
		if(cnt[1][1]) cnt[1][1]--, cSecond++;
		else if(cnt[0][1]) cnt[0][1]--, cSecond++;
		else if(cnt[1][0]) cnt[1][0]--;
		else cnt[0][0]--;
	}
	if(cFirst>cSecond) printf("First\n");
	else if(cFirst<cSecond) printf("Second\n");
	else printf("Draw\n");
}