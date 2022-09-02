#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define all(a) (a.begin(),a.end())

#define taskname "B"

using namespace std;

typedef long long int64;
typedef long double ld;

int main(){
	#ifdef LOCAL
		freopen(taskname".in","r",stdin);
		freopen(taskname".out","w",stdout);
	#endif
    int a,b,c;
	int a1,b1,c1;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&a1,&b1,&c1);
	if (a==0 && b==0){
		if (c!=0){
			printf("0\n");
			return 0;
		}
		if (a1==0 && b1==0 && c1!=0)
			{
				printf("0\n");
				return 0;
			}
		printf("-1\n");
		return 0;
	}
	if (a*b1!=a1*b){
		printf("1\n");
		return 0;
	}
	if ((a*c1!=c*a1) || (b*c1!=c*b1))
	{
		printf("0\n");
		return 0;
	}
	printf("-1\n");
    return 0;
}