#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
mt19937 rnd(time(nullptr));

void solve(){
    vector<vector<char> >A;
    vector<vector<int> >sum;
    int n,m;cin>>n>>m;
    A.resize(n);
    sum.resize(n);
    for (int i=0;i<n;i++) A[i].resize(m),sum[i].resize(m,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    queue<pair<int,int> >q;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (A[i][j]=='.'){
                for (int dx=-1;dx<=1;dx++){
                    for (int dy=-1;dy<=1;dy++){
                        if (dx && dy) continue;
                        if (!dx && !dy) continue;
                        int nw_x=i+dx,nw_y=j+dy;
                        if (nw_x<0 || nw_y<0 || nw_x>=n || nw_y>=m || A[nw_x][nw_y]=='#') continue;
                        sum[i][j]++;
                    }
                }
//                cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
            } else if (A[i][j]=='L'){
                q.push({i,j});
            }
        }
    }
    while (!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        sum[i][j]=-1;
        if (A[i][j]=='.') A[i][j]='+';
        for (int dx=-1;dx<=1;dx++){
            for (int dy=-1;dy<=1;dy++){
                if (dx && dy) continue;
                if (!dx && !dy) continue;
                int nw_x=i+dx,nw_y=j+dy;
                if (nw_x<0 || nw_y<0 || nw_x>=n || nw_y>=m || A[nw_x][nw_y]=='#') continue;
                if (sum[nw_x][nw_y]==-1) continue;
                sum[nw_x][nw_y]--;
                if (sum[nw_x][nw_y]<=1){
                    q.push({nw_x,nw_y});
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cout<<A[i][j];
        cout<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/*
10
100 2
4 4
25 25 25 25
25 25 25 25

10
100 3
5 5 5
10 10 10 10 60
10 10 10 10 60
10 10 10 10 60



10
5000 7
16 16 16 16 16 18 16
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 15 15 3 3 3 3 3 3 2 2 5 5 3 3 1 1
10 10 10 10 10 10 10 10 3 3 3 3 3 3 1 1

19638


2 2
2 2
1 1
1 1

10000 7
16 18 16 16 16 16 16
10 10 10 10 10 10 10 10 3 3 3 3 3 3 1 1
15 15 15 15 3 3
3 3 3 2 2 5
5 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1



15000 7
4 7 10 13 12 8 8
1000 1000 1000 12000
1000 1000 1000 1000 1000 1000 9000
1000 1000 1000 1000 1000 1000 1000 1000 1000 6000
1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 3000
1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 4000
1000 1000 1000 1000 1000 1000 1000 8000
1000 1000 1000 1000 1000 1000 1000 8000


10
20 7
4 7 10 13 12 8 8
1 1 1 17
1 1 1 1 1 1 14
1 1 1 1 1 1 1 1 1 11
1 1 1 1 1 1 1 1 1 1 1 1 8
1 1 1 1 1 1 1 1 1 1 1 9
1 1 1 1 1 1 1 13
1 1 1 1 1 1 1 13
*/