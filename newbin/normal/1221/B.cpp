#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 105;
int mp[105][105];
int n;
bool in(int x, int y){
    if(x < n && x >= 0 && y < n && y >= 0) return true; else return false;
}
int dx[8] = {-1,-1,-2,-2,1,1,2,2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};
void dfs(int x, int y, int c){
    mp[x][y] = c;
    for(int i = 0; i < 8; ++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(in(xx,yy) && !mp[xx][yy]) dfs(xx, yy, c^1);
    }
}
int main()
{
    cin>>n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!mp[i][j]) dfs(i, j, 2);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(mp[i][j]==2) printf("W"); else printf("B");
        }printf("\n");
    }
}