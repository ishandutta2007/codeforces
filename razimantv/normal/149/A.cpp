# include <cstdio>
# include <algorithm>
using namespace std;

int ar[13];

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<12;i++)
        scanf("%d",ar+i);
    sort(ar,ar+12);
    
    int tot=0;
    for(int i=12;i>=0;i--)
    {
        tot+=ar[i];
        if(tot>=N)
        {
            printf("%d\n",12-i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}