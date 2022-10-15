#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m,sud,slr,x,y,px,py;
vector<string> mp;
vector<char> path,cpath;
vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1},};
vector<char> f={'D','U','R','L'};
vector<vector<int>> vst;
    
void dfs(int i,int j){
        if (vst[i][j]) return;
        vst[i][j]=1;
        if(mp[i][j]=='F'){
            cpath=path;
            return;
        }
        for (int d=0;d<4;d++){
            int dx=dir[d][0];
            int dy=dir[d][1];
            int ni=i+dx; int nj=j+dy;
            if (0<=ni && ni<n && 0<=nj && nj<m && mp[ni][nj]!='*'){
                path.push_back(f[d]);
                dfs(ni,nj);
                path.pop_back();
            }
        }
 
    }
    
bool out(char c){
        cout<<c<<endl;
        cin>>x>>y;
        x--;y--;
        bool move=(px!=x || py!=y);
        px=x;py=y;
        return move;
 
    }
 
void solve(){
        cin>>n>>m;
        mp=vector<string>(n);
        for (int i=0;i<n;i++) cin>>mp[i];
        path=vector<char>();
        vst=vector<vector<int>>(n,vector<int>(m,0));
        dfs(0,0);
        sud =slr=-1;
         px=py=0;
        for (char c:cpath){
            if (c=='U' || c=='D'){
                if (sud!=-1){
                    out(((c=='U')^(sud))?'U':'D');
 
                }else{
                    if(!out('D'))
 
                    {
                        sud=1;
                        out('U');
                    }
                    else {
                        sud=0;
                    }
 
                }
            }else{
                if (slr!=-1){
                    out(((c=='L')^(slr))?'L':'R');
                }else{
                    if( !out('R'))
                    {
                        slr=1;
                        out('L');
                    }
                    else {
                        slr=0;
                    }
 
                }
            }
        }
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}