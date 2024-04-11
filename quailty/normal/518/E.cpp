#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=2000000005;
char a[100005][12];
int b[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i][0]=='?')b[i]=INF;
        else
        {
            int t=strlen(a[i]);
            if(a[i][0]=='-')
            {
                for(int j=1;j<t;j++)
                    b[i]=b[i]*10+a[i][j]-'0';
                b[i]=-b[i];
            }
            else
            {
                for(int j=0;j<t;j++)
                    b[i]=b[i]*10+a[i][j]-'0';
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        int l=0,r=0;
        for(int j=i;j<=n;j+=k)
        {
            if(j==i)
            {
                if(b[j]==INF)
                {
                    if(j+k>n)
                    {
                        if(l==0)
                        {
                            for(int p=i;p<=j;p+=k)
                            {
                                b[p]=(p-i)/k-((j-i)/k)/2;
                            }
                        }
                        else
                        {
                            if(b[l]>=-((j-l-k)/k)/2)
                            {
                                for(int p=l+k;p<=j;p+=k)
                                {
                                    b[p]=(p-l-k)/k+b[l]+1;
                                }
                            }
                            else
                            {
                                for(int p=l+k;p<=j;p+=k)
                                {
                                    b[p]=(p-l-k)/k-((j-l-k)/k)/2;
                                }
                            }
                        }
                    }
                }
                else
                {
                    l=j;
                    r=j;
                }
            }
            else
            {
                if(b[j]==INF)
                {
                    if(j+k>n)
                    {
                        if(l==0)
                        {
                            for(int p=i;p<=j;p+=k)
                            {
                                b[p]=(p-i)/k-((j-i)/k)/2;
                            }
                        }
                        else
                        {
                            if(b[l]>=-((j-l-k)/k)/2)
                            {
                                for(int p=l+k;p<=j;p+=k)
                                {
                                    b[p]=(p-l-k)/k+b[l]+1;
                                }
                            }
                            else
                            {
                                for(int p=l+k;p<=j;p+=k)
                                {
                                    b[p]=(p-l-k)/k-((j-l-k)/k)/2;
                                }
                            }
                        }
                    }
                }
                else
                {
                    r=j;
                    if(l==0)
                {
                    if(b[r]<=(r-k-i)/k-((r-k-i)/k)/2)
                    {
                        for(int p=i;p<=r-k;p+=k)
                        {
                            b[p]=b[r]-(r-k-p)/k-1;
                        }
                    }
                    else
                    {
                        for(int p=i;p<=r-k;p+=k)
                        {
                            b[p]=(p-i)/k-((r-k-i)/k)/2;
                        }
                    }
                }
                else
                {
                    if(b[l]>=-((r-l-2*k)/k)/2)
                    {
                        for(int p=l+k;p<=r-k;p+=k)
                        {
                            b[p]=(p-l-k)/k+b[l]+1;
                        }
                    }
                    else if(b[r]<=(r-l-2*k)/k-((r-l-2*k)/k)/2)
                    {
                        for(int p=l+k;p<=r-k;p+=k)
                        {
                            b[p]=b[r]-(r-k-p)/k-1;
                        }
                    }
                    else
                    {
                        for(int p=l+k;p<=r-k;p+=k)
                        {
                            b[p]=(p-l-k)/k-((r-l-2*k)/k)/2;
                        }
                    }
                }
                l=j;
                }
            }
        }
    }
    bool isok=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=i+k;j<=n;j+=k)
        {
            if(b[j]<=b[j-k])
            {
                isok=0;
                break;
            }
        }
    }
    if(isok)
    {
        for(int i=1;i<=n;i++)printf("%d ",b[i]);
    }
    else
    {
        printf("Incorrect sequence\n");
    }
    return 0;
}