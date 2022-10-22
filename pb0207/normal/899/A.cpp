#include<cstdio>
using namespace std;

int t[3],n;

int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),t[x]++;
	int ans=0;
	if(t[2]>=t[1])
		ans=t[1];
	else
	{
		ans=t[2];
		t[1]-=t[2];
		ans+=t[1]/3;
	}
	printf("%d",ans);
}