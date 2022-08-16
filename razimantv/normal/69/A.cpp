# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>
# include <queue>

using namespace std;
	
int main()
{
	int N;
	scanf("%d",&N);
	
	int x=0,y=0,z=0;
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		x+=a;y+=b;z+=c;
	}
	
	if(x==0&&y==0&&z==0)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}