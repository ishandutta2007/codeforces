# include <cstdio>

int height[100];

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%d",height+i);
    
    int minpos=0,maxpos=0;
    for(int i=1;i<N;i++)
    {
        if(height[i]>height[maxpos])maxpos=i;
        if(height[i]<=height[minpos])minpos=i;
    }
    
    int ret=maxpos+N-1-minpos;
    if(minpos<maxpos)ret--;
    printf("%d\n",ret);
}