#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int res=0;
	for (int i=1;i<=n;i++)
		if (i-1>=a&&n-i<=b) res++;
	printf("%d",res);
   return 0;
}