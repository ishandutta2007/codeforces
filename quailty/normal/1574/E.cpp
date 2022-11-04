#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=998244353;
int pw[MAXN];
int cnt_row[MAXN][2],cnt_col[MAXN][2],cnt_all[2];
int main()
{
    for(int i=(pw[0]=1);i<MAXN;i++)
        pw[i]=2*pw[i-1]%Mod;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    map<pair<int,int>,int> mp;
    int fre_row=n,fre_col=m;
    set<int> inv_row,inv_col;
    while(k--)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        if(mp.find({x,y})!=mp.end())
        {
            int t=mp[{x,y}];
            // printf("del %d %d %d\n",x,y,t);
            cnt_row[x][(y+t)&1]--;
            cnt_col[y][(x+t)&1]--;
            cnt_all[(x+y+t)&1]--;
            int fr=(!cnt_row[x][0] && !cnt_row[x][1]);
            int fc=(!cnt_col[y][0] && !cnt_col[y][1]);
            int ir=(cnt_row[x][0] && cnt_row[x][1]);
            int ic=(cnt_col[y][0] && cnt_col[y][1]);
            fre_row+=fr;
            fre_col+=fc;
            if(!ir)inv_row.erase(x);
            if(!ic)inv_col.erase(y);
            mp.erase({x,y});
        }
        if(t>=0)
        {
            // printf("add %d %d %d\n",x,y,t);
            int fr=(!cnt_row[x][0] && !cnt_row[x][1]);
            int fc=(!cnt_col[y][0] && !cnt_col[y][1]);
            fre_row-=fr;
            fre_col-=fc;
            cnt_row[x][(y+t)&1]++;
            cnt_col[y][(x+t)&1]++;
            cnt_all[(x+y+t)&1]++;
            int ir=(cnt_row[x][0] && cnt_row[x][1]);
            int ic=(cnt_col[y][0] && cnt_col[y][1]);
            if(ir)inv_row.insert(x);
            if(ic)inv_col.insert(y);
            mp[{x,y}]=t;
        }
        int res_row=(inv_row.empty() ? pw[fre_row] : 0);
        int res_col=(inv_col.empty() ? pw[fre_col] : 0);
        int res_all=2-(cnt_all[0]>0)-(cnt_all[1]>0);
        // printf("-- %d %d %d\n",res_row,res_col,res_all);
        printf("%d\n",((res_row+res_col-res_all)%Mod+Mod)%Mod);
    }
    return 0;
}