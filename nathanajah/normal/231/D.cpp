#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int x,y,z;
int x1,yy1,z1;
int a1,a2,a3,a4,a5,a6;
int res;
int main()
{
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d %d %d",&x1,&yy1,&z1);
	scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6);
	if (y<0)
		res+=a1;
	if (y>yy1)
		res+=a2;
	if (z<0)
		res+=a3;
	if (z>z1)
		res+=a4;
	if (x<0)
		res+=a5;
	if (x>x1)
		res+=a6;
	printf("%d\n",res);
}