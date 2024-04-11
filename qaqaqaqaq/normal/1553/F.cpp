#include<bits/stdc++.h>
#define int long long

using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// using namespace std;

const int maxn=300007;


int n;
const int B=500;
int C[maxn],D[maxn];
int a[maxn];

int lowbit(int u){
    return u&(-u);
}
void update(int u,int w){
    for (int i=u;i<=300000;i+=lowbit(i)){
        C[i]+=w, D[i]++;
    }
}
int query1(int u){
    int res=0;
    for (int i=u;i>0;i-=lowbit(i)) {res+=C[i];}
    return res;
}
int query2(int u){
    int res=0;
    for (int i=u;i>0;i-=lowbit(i)) res+=D[i];
    return res;
}

vi small;
signed main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    // n=200000;
    // rep(i,n) a[i]=i+100000;
    int sum=0,mx=0;
    rep(i,n){
        if (a[i]<B){
            rep(j,i) sum+=a[i]%a[j]+a[j]%a[i];
            small.pb(a[i]);
        }
        else{
            sum+=query1(300000);
            sum+=(i-sz(small))*a[i];
            for (auto c:small) sum+=a[i]%c+c;
            int lb=a[i]/B;
            rep1(j,lb+1){
                sum-=(query1(a[i]/j)-query1(a[i]/(j+1)))*j;
                // cout<<a[i]<<" "<<j<<" "<<query1(a[i]/j)<<" "<<query1(a[i]/(j+1))<<endl;
            }
            int ub=mx/a[i];
            rep1(j,ub+1){
                sum-=(query2(min(a[i]*(j+1)-1,300000ll)) - query2(min(a[i]*j-1,300000ll)))*j*a[i];
            }
            // cout<<query1(700)<<endl;
            update(a[i],a[i]);
            mx=max(mx,a[i]);
            // cout<<query1(700)<<endl;
        }
        cout<<sum<<" "; assert(sum>=0);
    }
    return 0;
}