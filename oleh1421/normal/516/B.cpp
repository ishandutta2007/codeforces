//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2010;
char a[N][N];
int d[N][N];
struct get_hash {
public:
    size_t operator()(const pair<int,int> &x) const {
        return (x.first*2000+x.second);
    }
};
unordered_set<pair<int,int>,get_hash>st[5];
//struct get_hash{
//public:
//    size_t operator()(const pair<int,int> &x) const{
//        return (x.first*2000+x.second);
//    }
//};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]!='.') continue;
            d[i][j]=(a[i][j-1]=='.')+(a[i][j+1]=='.')+(a[i-1][j]=='.')+(a[i+1][j]=='.');
            st[d[i][j]].insert({i,j});
        }
    }
    while (!st[0].empty() || !st[1].empty() || !st[2].empty() || !st[3].empty() || !st[4].empty()){
        if (!st[0].empty() || st[1].empty()){
            cout<<"Not unique\n";
            return 0;
        }
        auto cur=(*st[1].begin());
        st[1].erase(st[1].begin());
        int x=cur.first;
        int y=cur.second;

        int to_x=x,to_y=y;
        if (a[x][y-1]=='.'){
            a[x][y-1]='<';
            a[x][y]='>';
            to_y--;
        }
        else if (a[x][y+1]=='.') {
            a[x][y+1]='>';
            a[x][y]='<';
            to_y++;
        }
        else if (a[x-1][y]=='.'){
            a[x-1][y]='^';
            a[x][y]='v';
            to_x--;
        }
        else {
            a[x+1][y]='v';
            a[x][y]='^';
            to_x++;
        }

        for (int dx=-1;dx<=1;dx++){
            for (int dy=-1;dy<=1;dy++){
                if (!dx && !dy) continue;
                if (dx && dy) continue;
                if (a[x+dx][y+dy]=='.'){
                    st[d[x+dx][y+dy]].erase({x+dx,y+dy});
                    d[x+dx][y+dy]--;
                    st[d[x+dx][y+dy]].insert({x+dx,y+dy});
                }
                if (a[to_x+dx][to_y+dy]=='.'){
                    st[d[to_x+dx][to_y+dy]].erase({to_x+dx,to_y+dy});
                    d[to_x+dx][to_y+dy]--;
                    st[d[to_x+dx][to_y+dy]].insert({to_x+dx,to_y+dy});
                }
            }
        }
        st[d[to_x][to_y]].erase({to_x,to_y});

    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}

/*
3 - 4
*/