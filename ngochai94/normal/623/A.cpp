#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,adj[555][555],u,v,vst[555];
string s;
queue<int> q;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        u--;v--;
        adj[u][v]=adj[v][u]=1;
    }
    s="";
    For(i,0,n) s+='b';
    For(i,0,n) if(!vst[i])
    {
        vst[i]=1;
        q.push(i);
        bool flag=false;
        For(j,i+1,n) if(!adj[i][j]) flag=true;
        if(!flag)
        {
            continue;
        }
        s[i]='a';
        while(!q.empty())
        {
            v=q.front();q.pop();
            For(j,0,n) if(j!=v&&!adj[v][j])
            {
                if(s[j]==s[v])
                {
                    cout<<"NO";return 0;
                }
                if(!vst[j])
                {
                    vst[j]=1;
                    if(s[v]=='a') s[j]='c';
                    else s[j]='a';
                    q.push(j);
                }
            }
        }
    }
    //cout<<s<<endl;
    For(i,0,n) For(j,i+1,n)
    {
        if(adj[i][j]==1&&(s[i]=='a'&&s[j]=='c'||s[i]=='c'&&s[j]=='a')
           ||adj[i][j]==0&&(!(s[i]=='a'&&s[j]=='c'||s[i]=='c'&&s[j]=='a')))
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl<<s;
}