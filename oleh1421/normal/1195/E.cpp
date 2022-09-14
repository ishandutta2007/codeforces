#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int h[3010][3010];
int minx[3011][3011];
deque<int>Q;
void Push(int x){
     while (Q.size() && Q.back()>x) Q.pop_back();
     Q.push_back(x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;cin>>n>>m>>a>>b;
    int last,x,y,z;cin>>last>>x>>y>>z;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            h[i][j]=last;
            last=(last*x+y)%z;
        }
    }
    for (int i=1;i<=n;i++){
         Q.clear();
         for (int j=1;j<=b;j++){
              Push(h[i][j]);
         }
         minx[i][b]=Q.front();
         for (int j=b+1;j<=m;j++){
             if (Q.front()==h[i][j-b]) Q.pop_front();
             Push(h[i][j]);
             minx[i][j]=Q.front();
         }
    }
    int res=0ll;
    for (int i=b;i<=m;i++){
        Q.clear();
        for (int j=1;j<=a;j++) Push(minx[j][i]);
        res+=Q.front();
        for (int j=a+1;j<=n;j++){
            if (Q.front()==minx[j-a][i]) Q.pop_front();
            Push(minx[j][i]);
            res+=Q.front();
        }
    }
    cout<<res;
    return 0;
}