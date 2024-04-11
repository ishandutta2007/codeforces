#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
set<int> au[100002];
int m;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       int a,k;
       scanf("%d%d",&a,&k);
       if(a==0)
       {
          au[k].insert(a);
          continue;
       }
       if(au[k].find(a-1)!=au[k].end())
       {
          au[k].insert(a);
       }
       else if(au[k].find(a-1)==au[k].end())
       {
          m=1;
       }
    }
    if(m==1) puts("NO");
    else puts("YES");
    //system("pause");
    return 0;
}