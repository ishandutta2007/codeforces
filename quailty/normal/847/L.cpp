#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int MAXN=1005;
const int MAXL=100005;
vector<set<int> > subtree[MAXN];
int pos[MAXN][MAXN],usd[MAXN];
int nonempty[MAXN];
char buf[MAXL];
int ptr;
int read()
{
    char ch;
    while((ch=buf[ptr++])<'0' || ch>'9');
    int res=ch-'0';
    while((ch=buf[ptr++])>='0' && ch<='9')
        res=res*10+ch-'0';
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buf),ptr=0;
        int cnt=1;
        for(int j=0;buf[j];j++)
        {
            cnt+=(buf[j]=='-');
            if(buf[j]<'0' || buf[j]>'9')
                buf[j]=' ';
        }
        nonempty[i]=cnt;
        for(int t=0;t<cnt;t++)
        {
            set<int> tmp;
            int siz=read();
            for(int k=0;k<siz;k++)
            {
                int id=read();
                pos[id][i]=t;
                tmp.insert(id);
            }
            subtree[i].push_back(tmp);
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(auto &v:subtree[i])
//        {
//            printf("(");
//            for(auto &t:v)
//                printf("%d ",t);
//            printf(") ");
//        }
//        printf("\n");
//    }
    vector<pair<int,int> > res;
    for(int _=1;_<=n-1;_++)
    {
        int leaf=0;
        for(int i=1;i<=n;i++)
            if(!usd[i] && nonempty[i]==1)leaf=i;
        if(!leaf)return 0*printf("-1\n");
        int temp=0,cnt=0;
        usd[leaf]=1;
        for(int i=1;i<=n;i++)
        {
            if(usd[i])continue;
            set<int> &cur=subtree[i][pos[leaf][i]];
            cur.erase(leaf);
            if((int)cur.size()==0)
                nonempty[i]--,temp=i,cnt++;
        }
        if(cnt!=1)return 0*printf("-1\n");
        res.push_back(make_pair(leaf,temp));
    }
    printf("%d\n",(int)res.size());
    for(auto &t:res)
        printf("%d %d\n",t.first,t.second);
    return 0;
}