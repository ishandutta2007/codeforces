#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmin(a,b) a=min((int)(a),(int)(b))
#define chkmax(a,b) a=max(a,b)
using namespace std;
const int INF=4*1e18;


int32_t main(){
    int n,m;cin>>n>>m;
    int o1=0,e1=0,o2=0,e2=0,a;
    loop(i,0,n){
        cin>>a;
        if (a%2) e1++;
        else o1++;
    }
    loop(i,0,m){
        cin>>a;
        if (a%2) e2++;
        else o2++;
    }
    cout<<(min(e1,o2)+min(o1,e2))<<endl;
    return 0;
}