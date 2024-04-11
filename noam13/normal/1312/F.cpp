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
vvi grandy;
int grand(int i, int j){
    if (i<0) return grandy[0][j];
    return grandy[i][j];
}
int mex(int a, int b){
    loop(i,0,5) if (i!=a && i!=b) return i;
    cout<<"FUCK"<<endl;
    return -1;
}
int mex(int a, int b, int c){
    loop(i,0,5) if (i!=a && i!=b && i!=c) return i;
    cout<<"FUCK"<<endl;
    return -1;
}
int cycle, start;
int getgrandy(int a, int j=0){
    if (a<=start) return grandy[a][j];
    a = (a-start)%cycle;
    return grandy[start+a][j];
}
void solve(){
    int n,x,y,z; cin>>n>>x>>y>>z;
    vi step = {x,y,z};
    grandy.clear(); grandy.resize(1,vi(3,0));
    map<vvi, int> check;
    cycle=-1; start=-1;
    loop(i,1,INF){
        grandy.pb(vi(3,0));
        grandy[i][0] = mex(grand(i-x, 0), grand(i-y, 1), grand(i-z, 2));
        grandy[i][1] = mex(grand(i-x, 0), grand(i-z, 2));
        grandy[i][2] = mex(grand(i-x, 0), grand(i-y, 1));
        if (i>=4){
            vvi prev(5,vi(3));
            loop(k,0,5) loop(j,0,3) prev[k][j] = grandy[i-4+k][j];
            if (check[prev]){
                cycle = i-check[prev];
                start = check[prev];
                break;
            }
            else check[prev] = i;
        }
    }
    //cout<<"AA"<<start<<" "<<cycle<<endl;
    vi a(n);
    int mygrand = 0;
    loop(i,0,n){
        cin>>a[i];
        mygrand^=getgrandy(a[i]);
    }
    //cout<<"GRAND: "<<mygrand<<endl;
    int ans=0;
    loop(i,0,n){
        loop(j,0,3){
            int v = getgrandy(a[i]) ^ getgrandy(max(a[i]-step[j],int(0)),j);
            if (v==mygrand) ans++;
        }
    }
    cout<<ans<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
3
2 1 3 4
7 6
1 1 2 3
1
1 1 2 2
3



*/