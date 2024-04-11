#include<bits/stdc++.h>
using namespace std;
const int MAXN=305;
const int MAXL=100005;
map<string,int> mp;
inline int get_id(const string &t)
{
    if(!mp[t])mp[t]=(int)mp.size();
    return mp[t];
}
int fail[MAXN];
void get_fail(int a[],int n)
{
    fail[1]=0;
    for(int i=1;i<n;i++)
    {
        int p=fail[i];
        while(p && a[p+1]!=a[i+1])p=fail[p];
        fail[i+1]=p+(a[p+1]==a[i+1]);
    }
}
int match(int a[],int n,int b[],int m)
{
    int res=0;
    for(int i=1,j=0;i<=m;i++)
    {
        while(j && b[i]!=a[j+1])j=fail[j];
        j+=(b[i]==a[j+1]);
        if(j==n)res++,j=0;
    }
    return res;
}
char buff[MAXL];
int a[MAXN],len[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buff);
        a[i]=get_id(buff);
        len[i]=strlen(buff);
    }
    int sum=n-1;
    for(int i=1;i<=n;i++)
        sum+=len[i];
    int res=sum;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            get_fail(a+i-1,j-i+1);
            int cnt=match(a+i-1,j-i+1,a,n);
            if(cnt>=2)
            {
                int tot=j-i;
                for(int k=i;k<=j;k++)
                    tot+=len[k]-1;
                res=min(res,sum-tot*cnt);
            }
        }
    printf("%d\n",res);
    return 0;
}