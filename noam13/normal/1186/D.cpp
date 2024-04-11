#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;
const double eps=1e-6;

bool notZero(double a){
    return a>eps || a<-eps;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n; cin>>n;
    vector<double> a(n);
    loop(i,0,n) cin>>a[i];
    long double sum=0;
    loop(i,0,n){
        sum+=a[i]-floor(a[i]);
    }
    int cnt=round(sum);
    loop(i,0,n){
        if (cnt>0 && notZero(a[i]-floor(a[i])) ){
            cnt--;
            cout<<floor(a[i])+1<<endl;
        }
        else cout<<floor(a[i])<<endl;
    }
    //cout<<sum<<endl;
    return 0;
}