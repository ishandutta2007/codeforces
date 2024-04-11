#include <bits/stdc++.h>
//#define int long long
//#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,long long>
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;



int dis(int x,int y,int n){
    return (y-x+((y-x>=0)?0:n));
}

int main()
{
    cout << fixed << showpoint << setprecision(15);
    int n,m,x,y,maxC,v;
    long double avg;
    cin >> n>>m;
    vector<vector<int> > g (n);
    vector<int> c (n);
    for (int i=0;i<m;i++){
        cin >> x>> y; x--;y--;
        g[x].pb(dis(x,y,n));
    }
    for (int i=0;i<n;i++){
        sort(all(g[i]));
        c[i]=g[i].size()>0?g[i][0]:-1e5;
    }
    for(int i=0;i<n;i++){
        maxC=0;
        for(int j=0;j<n;j++){
            v=c[j]+(g[j].size()-1)*n+dis(i,j,n);
            maxC=max(maxC,v);
        }
        cout << maxC << ((i<n-1)?" ":"");
    }
    cout <<endl;
    return 0;
}