
 #include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN],b[MAXN];
vector<int>seg[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&b[i]);
    for(int i=1,j=1;i<=k;i++)
    {
        while(j<=n && b[i]>0)
        {
            seg[i].push_back(j);
            b[i]-=a[j++];
        }
        if(i==k && j<=n)return 0*printf("NO");
        if(b[i]!=0)return 0*printf("NO");
    }
    for(int i=1;i<=k;i++)
    {
        if((int)seg[i].size()==1)continue;
        int mi=a[seg[i][0]],mx=a[seg[i][0]];
        for(int j=0;j<(int)seg[i].size();j++)
            mi=min(mi,a[seg[i][j]]),mx=max(mx,a[seg[i][j]]);
        if(mi==mx)return 0*printf("NO");
    }
    printf("YES\n");
    for(int i=1;i<=k;i++)
    {
        int mx=a[seg[i][0]];
        for(int j=0;j<(int)seg[i].size();j++)
            mx=max(mx,a[seg[i][j]]);
        bool isok=0;
        for(int j=0;j+1<(int)seg[i].size() && !isok;j++)
            if(a[seg[i][j]]==mx && a[seg[i][j+1]]<mx)
            {
                for(int k=j;k+1<(int)seg[i].size();k++)
                    printf("%d R\n",i+j);
                for(int k=j;k>0;k--)
                    printf("%d L\n",i+k);
                isok=1;
            }
        for(int j=1;j<(int)seg[i].size() && !isok;j++)
            if(a[seg[i][j]]==mx && a[seg[i][j-1]]<mx)
            {
                for(int k=j;k>0;k--)
                    printf("%d L\n",i+k);
                for(int k=j;k+1<(int)seg[i].size();k++)
                    printf("%d R\n",i);
                isok=1;
            }
    }
    return 0;
}