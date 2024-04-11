#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a;
        ll t = 1;
        fors(i,0,n){
            ll x; scanf("%lld", &x);
            while(x%2 == 0) x/=2, t*=2; a.pb(x);
        }
        sort(all(a));
        ll sum = 0; for(int x:a) sum += x;
        sum -= a.back(); sum += a.back()*t;
        cout<<sum<<endl;
    }
    return 0;
}