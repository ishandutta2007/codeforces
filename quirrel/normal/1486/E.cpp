#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int> > v[200009];
int d[200009][52];
int f[200009][52];
int inf = 2e9;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i =1 ;i <= m; i++){
        int a, b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i =1 ; i <=n ;i++){
        for(int j = 0; j <= 50; j++){
            d[i][j] = inf;
        }
    }
    priority_queue<pair<int,pair<int,int> >  > q;
    q.push({0,{1,0}});
    d[1][0] = 0;
    while(q.size()){
        int x = q.top().second.first;
        int w = q.top().second.second;
        q.pop();
        if(f[x][w]) continue;
        f[x][w] = 1;
        int L = d[x][w];
        for(auto E : v[x]){
            int y = E.first, w1 = E.second;
            int nw = 0, L1 = 0;
            if(w == 0){
                nw = w1, L1 = L;
            }
            else{
                nw = 0, L1 = (L + (w1 + w)*(w1+w));
            }
            if(f[y][nw] == 0 && L1 < d[y][nw]){
                d[y][nw] = L1;
                q.push({-L1, {y, nw}});
            }
        }


    }
    for(int i = 1; i <= n; i++){
        if(d[i][0] == inf) cout <<-1<<" ";
        else cout<<d[i][0]<<" ";
    }
    cout<<endl;



}