#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=105;
int main()
{
	int r,x,y,x1,y1;
	scanf("%d%d%d%d%d",&r,&x,&y,&x1,&y1);
	long long t=(x-x1)*1ll*(x-x1)+(y-y1)*1ll*(y-y1);
	long long l=sqrt(t);
	if(l*l!=t)
		l++;
	r*=2;
	printf("%I64d\n",(l+r-1)/r);
	return 0;
}