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

int arr[1000];
bool flag=true;

void makeearliest(int &n,int &early)
{
    char a[4],b[4];
    b[3]=n%10;
    b[2]=(n/10)%10;
    b[1]=(n/100)%10;
    b[0]=(n/1000)%10;
    
    for(int i=early;i<=2011;i++)
    {
        a[3]=i%10;
        a[2]=(i/10)%10;
        a[1]=(i/100)%10;
        a[0]=(i/1000)%10;
        
        int cnt=0;
        for(int j=0;j<4;j++)
            if(a[j]!=b[j])cnt++;
        if(cnt<2)
        {
            n=early=i;
            return;
        }
    }
    flag=false;
}

int main()
{
    int N;
    scanf("%d",&N);
    
    int earliest=1000;
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
        if(flag)makeearliest(arr[i],earliest);
    }
    
    if(flag)for(int i=0;i<N;i++)printf("%d\n",arr[i]);
    else printf("No solution\n");
    
    return 0;
}