#include <cstdio>
using namespace std;

int cnt[1000001];
int canFile[1000001];

int main()
{
	int N;
	int a;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
		canFile[a]++;
	}
	for(int i=1000000;i>0;i--)
	{
		if((cnt[i]%2)&&(canFile[i]>0))
		{
			cnt[i]--;
			cnt[i-1]++;
			canFile[i]--;
		}
	}
	int prev;
	for(prev=1000000;prev>=0;prev--)
		if(cnt[prev]>0)
			break;
	long long total = 0;
	if(prev<0)
	{
		printf("0\n");
		return 0;
	}
	int ccur = -1;
	for(int i=prev;i>0;)
	{
		if(cnt[i]<2)
		{
			i--;
		}
		else if(ccur==-1)
		{
			ccur = i;
			cnt[i] -= 2;
		}
		else
		{
			total += ((long long)i)*((long long)ccur);
			cnt[i] -= 2;
			ccur = -1;
		}
	}
	printf("%I64d\n",total);
	return 0;
}