# include <cstdio>

int N,M,K;
char decided[2000];int numrand=0;

void work(int i)
{
    for(int j=0;j<K;j++)
    {
        int st=i-j;
        int end=st+K-1;
        if(st<0||end>=N)continue;
        int match=end+st-i;
        if(!decided[match])
        {
            decided[match]=1;
            work(match);
        }
    }
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    
    for(int i=0;i<N;i++)
    {
        if(decided[i])continue;
        decided[i]=1;
        numrand++;
        work(i);
    }
    
    long long ret=1;
    for(int i=0;i<numrand;i++)
        ret=(ret*M)%1000000007;
    printf("%d\n",(int)ret);
}