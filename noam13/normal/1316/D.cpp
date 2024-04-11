#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

int n;
vvii dest;
vvi ans;
vii dir = {{1,0},{-1,0},{0,1},{0,-1}};
vector<char> conv = {'D','U','R','L','X'};
bool pos = true;
int anti(int k){
    if (k==0) return 1;
    if (k==1) return 0;
    if (k==3) return 2;
    return 3;
}
void dfs(int i, int j, ii d, int p=-1){
    if (i<0 || i>=n || j<0 || j>=n) return ;
    if (dest[i][j]!=d) return ;
    if (ans[i][j]!=-1) return ;
    if (d == ii(i,j)) ans[i][j] = 4;
    else ans[i][j] = anti(p);
    loop(k,0,4){
        dfs(i+dir[k].x,j+dir[k].y,d,k);
    }
}
bool dfs2(int i, int j){
    if (i<0 || i>=n || j<0 || j>=n) return false;
    if (dest[i][j].x!=-1) return false;
    if (ans[i][j]!=-1) return true;
    ans[i][j] = 5;
    loop(k,0,4){
        if (dfs2(i+dir[k].x,j+dir[k].y)){
            ans[i][j] = k;
            return true;
        }
    }
    pos = false;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    dest.resize(n, vii(n));
    ans.resize(n, vi(n,-1));
    loop(i,0,n) loop(j,0,n) {
        cin>>dest[i][j].x>>dest[i][j].y;
        if (dest[i][j].x!=-1) dest[i][j].x--, dest[i][j].y--;
    }
    loop(i,0,n){
        loop(j,0,n){
            if (dest[i][j] == ii(i,j)) dfs(i,j,dest[i][j]);
        }
    }
    loop(i,0,n){
        loop(j,0,n){
            if (ans[i][j]==-1) dfs2(i,j);
        }
    }
    loop(i,0,n){
        loop(j,0,n){
            if (ans[i][j]==-1) pos = false;
        }
    }
    if (pos){
        cout<<"VALID"<<endl;
    loop(i,0,n){
        loop(j,0,n){
            if (ans[i][j]!=-1) cout<<conv[ans[i][j]];
        }
        cout<<endl;
    }
    }
    else cout<<"INVALID"<<endl;

    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
2
1 1 1 1
2 2 2 2

*/