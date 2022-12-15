#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back
#define off 600000

int n,m,vst[1111][1111],ans[1111111],cnt,dx[]={1,-1,0,0},dy[]={0,0,1,-1},len;
string grid[1111];
stack<pair<int,int> > s;

bool valid(int r,int c)
{
    if(r>=0&&c>=0&&r<n&&c<m&&grid[r][c]=='.') return true;
    return false;
}

void dfs(int r,int c)
{
    while(!s.empty()) s.pop();
    vst[r][c]=++cnt;
    len=1;
    s.push({r,c});
    while(!s.empty())
    {
        r=s.top().first;
        c=s.top().second;
        s.pop();
        For(d,0,4)
        {
            int rr=r+dx[d];
            int cc=c+dy[d];
            if(valid(rr,cc)&&!vst[rr][cc])
            {
                vst[rr][cc]=cnt;
                s.push({rr,cc});
                len++;
            }
        }
    }
    ans[cnt]=len;
}

vector<int> v;

int main(){
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,n) cin>>grid[i];
    reset(vst,0);
    reset(ans,0);
    cnt=0;
    For(i,0,n) For(j,0,m) if(grid[i][j]=='.' && !vst[i][j]) dfs(i,j);
    For(i,0,n)
    {
        For(j,0,m)
        {
            if(grid[i][j]=='.') cout<<'.';
            else
            {
                v.clear();
                int ret=1;
                For(d,0,4)
                {
                    int rr=i+dx[d];
                    int cc=j+dy[d];
                    if(valid(rr,cc))
                    {
                        bool flag=false;
                        for(int i:v) if(i==vst[rr][cc]) flag=true;
                        v.pb(vst[rr][cc]);
                        if(!flag) ret+=ans[vst[rr][cc]];
                    }
                }
                cout<<ret%10;
            }
        }
        cout<<endl;
    }
}