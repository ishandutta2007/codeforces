#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int r[105];
char out[105];
vector<int>now[105];
vector<vector<int> >opt;
void ok(int n,int res)
{
    opt.clear();
    for(int i=0;i<=100;i++)
        now[i].clear();
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=r[i]-res;
        now[r[i]-res].push_back(i);
    }
    if(sum&1)
    {
        vector<int>tmp,cur;
        int cnt=3;
        for(int i=100;i>0;i--)
        {
            while(cnt && !now[i].empty())
            {
                tmp.push_back(now[i].back());
                cur.push_back(i);
                now[i].pop_back();
                cnt--;
            }
        }
        opt.push_back(tmp);
        for(int i=0;i<(int)tmp.size();i++)
            now[cur[i]-1].push_back(tmp[i]);
    }
    while(1)
    {
        vector<int>tmp,cur;
        int cnt=2;
        for(int i=100;i>0;i--)
        {
            while(cnt && !now[i].empty())
            {
                tmp.push_back(now[i].back());
                cur.push_back(i);
                now[i].pop_back();
                cnt--;
            }
        }
        if(tmp.empty())break;
        opt.push_back(tmp);
        for(int i=0;i<(int)tmp.size();i++)
            now[cur[i]-1].push_back(tmp[i]);
    }
    printf("%d\n%d\n",res,(int)opt.size());
    for(int i=0;i<(int)opt.size();i++)
    {
        for(int j=0;j<n;j++)out[j]='0';
        for(int j=0;j<(int)opt[i].size();j++)
            out[opt[i][j]-1]='1';
        printf("%s\n",out);
    }
    exit(0);
}
int cur[105];
void check(int n,int res)
{
    for(int i=1;i<=n;i++)
        cur[i]=r[i]-res;
    sort(cur+1,cur+n+1);
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=cur[i];
    if(sum&1)
    {
        if(n<3)return;
        for(int i=n;i>=n-2;i--)
            if(--cur[i]<0)return;
    }
    sort(cur+1,cur+n+1);
    sum=0;
    for(int i=1;i<=n-1;i++)
        sum+=cur[i];
    if(sum<cur[n])return;
    sum=0;
    for(int i=1;i<=n;i++)
        sum+=(cur[i]>0);
    if(sum==1)return;
    if(sum==2 && cur[n-1]!=cur[n])return;
    ok(n,res);
}
void gg(int n)
{
    printf("0\n%d\n",(n-1)*100);
    for(int i=1;i<=n-1;i++)
        for(int _=0;_<100;_++,printf("\n"))
            for(int j=1;j<=n;j++)printf("%c",((j==i || j==i+1) ? '1' : '0'));
}
int main()
{
    int n;
    scanf("%d",&n);
    int mi=100;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
        mi=min(mi,r[i]);
    }
    for(int i=mi;i>0;i--)
        check(n,i);
    gg(n);
    return 0;
}