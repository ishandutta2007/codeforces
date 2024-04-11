#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
char s[1000005];
int nex[1000005];
void kmp()
{
    nex[0]=-1;
    for(int i=0;i<n-1;i++)
    {
        int k=nex[i];
        while(k!=-1)
        {
            if(s[i+1]==s[k+1])
            {
                nex[i+1]=k+1;
                break;
            }
            k=nex[k];
        }
        if(k==-1)
        {
            nex[i+1]=(s[i+1]==s[k+1] ? 0 : -1);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    kmp();
    for(int i=0;i<n;i++)
    {
        int t=(i+1)/(i-nex[i]);
        if((i+1)%(i-nex[i])==0)
        {
            if(t/k>=t%k)
            {
                printf("1");
            }
            else printf("0");
        }
        else
        {
            if(t/k>t%k)
            {
                printf("1");
            }
            else printf("0");
        }
    }
    return 0;
}