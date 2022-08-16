# include <cstdio>
# include <iostream>
# include <vector>
# include <set>
# include <algorithm>

using namespace std;

char inp[1000000];

int main()
{
	scanf("%s",inp);
	bool removed=false;

	for(int i=0;inp[i];i++)
	{
		if((removed==false)&&((inp[i]=='0')||(inp[i+1]==0)))removed=true;
		else printf("%c",inp[i]);
	}
	printf("\n");
	return 0;
}