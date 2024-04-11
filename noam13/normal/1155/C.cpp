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

int gcd(int a, int b) {
   if (b == 0) return a;
   if (b>a) swap(a,b);
   return gcd(b, a % b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}


int32_t main(){
    int n,m;cin>>n>>m;
    int d,g;
    vi e(n),pos(m);
    loop(i,0,n) {
        cin>>e[i];
    }
    g=e[1]-e[0];
    loop(i,1,n-1){
        d=e[i+1]-e[i];
        g=gcd(d,g);
    }
    loop(i,0,m) {
        cin>>pos[i];
    }
    loop(i,0,m) {
        if (g%pos[i]==0){
            cout<<"YES"<<endl;
            cout<< e[0] << " " << (i+1) <<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}