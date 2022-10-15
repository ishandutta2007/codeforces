#include <bits/stdc++.h>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 500000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
vector<int> G[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<n-1<<endl;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        cout<<2<<' '<<x<<' '<<y<<endl;
 
        x--;
        y--;
        G[x].push_back(i);
        G[y].push_back(i);
    }
 
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<G[i].size()-1;j++)
            cout<<G[i][j]<<' '<<G[i][j+1]<<endl;
 
}