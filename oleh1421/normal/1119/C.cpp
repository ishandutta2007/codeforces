#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int maxx[300001];
int minx[300001];
int a[501][501];
int b[501][501];
int main()
{
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    vector<int>v;
    for (int j=1;j<=m;j++){
        int cur=0;
        for (int i=1;i<=n;i++){
            cur^=a[i][j];
        }
        v.push_back(cur);
    }
    vector<int>u;
    for (int j=1;j<=m;j++){
        int cur=0;
        for (int i=1;i<=n;i++){
            cur^=b[i][j];
        }
        u.push_back(cur);
    }
    vector<int>v1;
    for (int i=1;i<=n;i++){
        int cur=0;
        for (int j=1;j<=m;j++){
            cur^=a[i][j];
        }
        v1.push_back(cur);
    }
    vector<int>u1;
    for (int i=1;i<=n;i++){
        int cur=0;
        for (int j=1;j<=m;j++){
            cur^=b[i][j];
        }
        u1.push_back(cur);
    }
    if (v==u && v1==u1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
/*
3 4
0 1 0 1
1 0 1 0
0 1 0 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1
1 3
2 2
2 4
3 1
3 3
*/