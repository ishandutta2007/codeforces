#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
//#define abs(a) ((a)>0?a:-(a))
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

inline void print(int i,int j){
    cout<<(i+1)<<" "<<(j+1)<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n,m; cin>>n>>m;
    loop(i,0,n/2){
        loop(j,0,m){
            cout<<(i+1)<<" "<<(j+1)<<"\n";
            cout<<(n-i)<<" "<<(m-j)<<"\n";
        }
    }
    if (n%2){
        loop(j,0,m/2){
            cout<<(n/2+1)<<" "<<(j+1)<<"\n";
            cout<<(n/2+1)<<" "<<(m-j)<<"\n";
        }
        if (m%2) cout<<(n/2+1)<<" "<<(m/2+1)<<"\n";
    }
    return 0;
}