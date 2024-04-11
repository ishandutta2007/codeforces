#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
inline char query_char(int i)
{
    printf("? 1 %d\n",i);
    fflush(stdout);
    char ch[5];
    scanf("%s",ch);
    return ch[0];
}
inline int query_cnt(int l,int r)
{
    printf("? 2 %d %d\n",l,r);
    fflush(stdout);
    int cnt;
    scanf("%d",&cnt);
    return cnt;
}
int pre[MAXN];
char res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> last;
    last.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int l=0,r=(int)last.size()-1;
        while(l<r)
        {
            int m=(l+r+1)/2;
            if(query_cnt(last[m],i)<=(int)last.size()-m)l=m;
            else r=m-1;
        }
        pre[i]=last[l];
        if(l>0)last.erase(last.begin()+l);
        last.push_back(i);
    }
    for(size_t i=1;i<last.size();i++)
    {
        char t=query_char(last[i]);
        for(int j=last[i];j;j=pre[j])
            res[j]=t;
    }
    return 0*printf("! %s\n",res+1);
}