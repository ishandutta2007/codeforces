#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
struct event
{ 
 int a,b;
};
bool cmp(event x,event y) {return x.a<y.a;}

int main() {
    int n; 
    scanf("%d",&n);
    event d[n+1];
    for (int i=1;i<=n;i++)
     scanf("%d%d",&d[i].a,&d[i].b);
    sort(d+1,d+n+1,cmp);
    set <int> s; int res=0; set <int>::iterator it; 
	s.insert(d[1].b);
	for (int i=2;i<=n;i++)
	{
		it=s.end();it--;
		if (*it>d[i].b) res++;
		s.insert(d[i].b);
	}
	printf("%d",res);
    return 0;
}