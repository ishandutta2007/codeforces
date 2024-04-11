#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
const int INF=0x3f3f3f3f;
char s[MAXN],t[MAXN];
int dis[MAXN][MAXN][MAXN];
tuple<char,int,int,int> pre[MAXN][MAXN][MAXN];
int main()
{
    scanf("%s%s",s,t);
    int lens=strlen(s),lent=strlen(t);
    int n=max(lens,lent);
    queue<tuple<int,int,int>> q;
    q.push(tuple<int,int,int>{0,0,0});
    memset(dis,INF,sizeof(dis));
    dis[0][0][0]=0;
    while(!q.empty())
    {
        int i,j,k;
        tie(i,j,k)=q.front();
        q.pop();
        for(auto c:{'(',')'})
        {
            int ti=i+(i<lens && s[i]==c);
            int tj=j+(j<lent && t[j]==c);
            int tk=k+(c=='(' ? 1 : -1);
            if(tk>=0 && tk<=n && dis[ti][tj][tk]>dis[i][j][k]+1)
            {
                q.push(tuple<int,int,int>{ti,tj,tk});
                dis[ti][tj][tk]=dis[i][j][k]+1;
                pre[ti][tj][tk]=tuple<char,int,int,int>{c,i,j,k};
            }
        }
    }
    string res="";
    int ni=lens,nj=lent,nk=0;
    while(ni>0 || nj>0 || nk>0)
    {
        char c;
        tie(c,ni,nj,nk)=pre[ni][nj][nk];
        res+=c;
    }
    reverse(res.begin(),res.end());
    return 0*printf("%s\n",res.c_str());
}