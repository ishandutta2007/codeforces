#include <bits/stdc++.h>
#define int uint64_t
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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int u,v; cin>>u>>v;
    if (u>v || (v-u)%2) return cout<<-1<<endl,0;
    if (u==v && v==0) return cout<<0<<endl,0;
    if (u==v) return cout<<1<<endl<<u<<endl,0;
    int d = (v-u)/2;
    if ((u|d)+d==v) return cout<<2<<endl<<(u|d)<<" "<<d<<endl,0;
    cout<<3<<endl<<u<<" "<<d<<" "<<d<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o b & b
2 4

1000000000000000000
1000000000000000002
*/