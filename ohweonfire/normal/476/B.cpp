#include <cstdio>
#include <cstring>
using namespace std;
char b[15],a[15];
int pos,len,unknown,finalpos;
int main()
{
	scanf("%s%s",a,b);
	len=strlen(b);
	for(int i=0;i<len;i++)
		if(b[i]=='+')
			pos++;
		else if(b[i]=='-')
			pos--;
		else
			unknown++;
	for(int i=0;i<len;i++)
		if(a[i]=='+')
			finalpos++;
		else
			finalpos--;
	int cnt=0;
	for(int mask=0;mask< 1 << unknown; mask++)
	{
		int poss=pos;
		for(int i=0;i<unknown;i++){
			if(mask>>i&1)
				poss++;
			else
				poss--;}
		if(poss==finalpos)
			cnt++;
	}
	printf("%.9lf\n",cnt*1.0/(1<<unknown));
	return 0;
}