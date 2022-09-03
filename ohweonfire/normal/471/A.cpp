#include <cstdio>
using namespace std;
int cnt[10],x;
bool elephant()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			if((cnt[i]==4&&cnt[j]==2)||(i==j&&cnt[i]==6))
				return true;
	return false;
	
}
bool bear()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			for(int k=j+1;k<=9;k++)
				if(cnt[i]==4&&cnt[j]==1&&cnt[k]==1||(cnt[i]==5&&i==j&&cnt[k]==1)||(cnt[i]==5&&i==k&&cnt[j]==1))
					return true;
	return false;
}
int main()
{
	for(int i=0;i<6;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	if(elephant())
		puts("Elephant");
	else if(bear())
		puts("Bear");
	else
		puts("Alien");
	return 0;
}