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

const int UP=1,DOWN=-1;
char arr[100][50];
int party[26];

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%d",&party[i]);
    
    if(b<d)
        for(int i=0;i<a;i++)
            for(int j=b;j<d;j++)
                arr[i][j]='.';
    else
        for(int i=a;i<a+c;i++)
            for(int j=d;j<b;j++)
                arr[i][j]='.';
    
    int x,y,dirn;
    if(a&1)
        x=0,y=b-1,dirn=DOWN;
    else
        x=0,y=0,dirn=UP;
    
    for(int p=0,used=0;p<N;)
    {
        arr[x][y]='a'+p;
        used++;
        if(used==party[p])
        {
            p++;
            used=0;
        }
        y+=dirn;
        if(y<0)
        {
            y=0;x++;
            dirn=-dirn;
        }
        if((x<a&&y>=b)||(x>=a&&y>=d))
        {
            dirn=-dirn;
            if(x<a)y=b-1;
            else y=d-1;
            x++;
        }
    }
    printf("YES\n");
    for(int i=0;i<max(b,d);i++)
    {
        for(int j=0;j<a+c;j++)
            printf("%c",arr[j][i]);
        printf("\n");
    }
    return 0;
}