#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "petrol.inp"
#define FILE_OUT "petrol.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define endl "\n"
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
int n,m,i,j,k,t,t1,p,aad,bad,bruh[30],cnt=0,maxx=0;
int a[1000002],b[1000002];
pii dest[1000][1000];
int reg[1000][1000];
char res[1000][1000];
bitset <10001> gud;
string s,md[5001];
vector<int> v;
bool valid (int x, int y)
{
    return ((x>=0)and(x<n)and(y>=0)and(y<m));
}
void dfs1(pii cur)
{
    int x=cur.fi, y=cur.se;
    if ((valid(x,y+1))and(reg[x][y+1]==-1))
    {
        res[x][y]='R';
    }
    if ((valid(x,y-1))and(reg[x][y-1]==-1))
    {
        res[x][y]='L';
    }
    if ((valid(x-1,y))and(reg[x-1][y]==-1))
    {
        res[x][y]='U';
    }
    if ((valid(x+1,y))and(reg[x+1][y]==-1))
    {
        res[x][y]='D';
    }
    if ((valid(x,y+1))and(reg[x][y+1]==-1)and(res[x][y+1]==' '))
    {
        dfs1({x,y+1});
    }
    if ((valid(x,y-1))and(reg[x][y-1]==-1)and(res[x][y-1]==' '))
    {
        dfs1({x,y-1});
    }
    if ((valid(x-1,y))and(reg[x-1][y]==-1)and(res[x-1][y]==' '))
    {
        dfs1({x-1,y});
    }
    if ((valid(x+1,y))and(reg[x+1][y]==-1)and(res[x+1][y]==' '))
    {
        dfs1({x+1,y});
    }
}
void dfs2(pii cur, pii prev)
{
    int x=cur.fi, y=cur.se;
    if (prev.fi==x+1) res[x][y]='D';
    else if (prev.fi==x-1) res[x][y]='U';
    else if (prev.se==y-1) res[x][y]='L';
    else if (prev.se==y+1) res[x][y]='R';
    if ((valid(x,y+1))and(reg[x][y+1]==reg[i][j])and(res[x][y+1]==' '))
    {
        dfs2({x,y+1},{x,y});
    }
    if ((valid(x,y-1))and(reg[x][y-1]==reg[i][j])and(res[x][y-1]==' '))
    {
        dfs2({x,y-1},{x,y});
    }
    if ((valid(x-1,y))and(reg[x-1][y]==reg[i][j])and(res[x-1][y]==' '))
    {
        dfs2({x-1,y},{x,y});
    }
    if ((valid(x+1,y))and(reg[x+1][y]==reg[i][j])and(res[x+1][y]==' '))
    {
        dfs2({x+1,y},{x,y});
    }
}
int main(){
  //  ofile;
    fio;
    cin>>n;
    m=n;
    
    for (i=0;i<n;i++) for (j=0;j<m;j++)
    {
        cin>>aad>>bad;
        aad--;
        bad--;
        dest[i][j]={aad,bad};
    }
    for (i=0;i<n;i++) for (j=0;j<m;j++)
    {
        int x=dest[i][j].fi;
        int y=dest[i][j].se;
        if (x==-2) continue;
        if (!((dest[x][y].fi==x)and(dest[x][y].se==y))) {cout<<"INVALID"; return 0;}
    }
    for (i=0;i<n;i++) for (j=0;j<m;j++)
    {
        aad=dest[i][j].fi;
        bad=dest[i][j].se;
        if (aad==-2) reg[i][j]=-1;
        else
        {
        if (!reg[aad][bad]) {k++; reg[aad][bad]=k;}
        reg[i][j]=reg[aad][bad];
        }
        res[i][j]=' ';
    }
    for (i=0;i<n;i++) for (j=0;j<m;j++)
    {
        if ((reg[i][j]==-1)and(res[i][j]==' ')) dfs1({i,j});
        else if ((i==dest[i][j].fi)and(j==dest[i][j].se)) {res[i][j]='X'; dfs2({i,j},{i,j});}
    }
    for (i=0;i<n;i++) for (j=0;j<m;j++) if (res[i][j]==' ') {cout<<"INVALID"; return 0;}
    {
        cout<<"VALID\n";
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++) cout<<res[i][j];
            cout<<endl;
        }
    }
}