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
    int n, m;
    cin>>n>>m;
    #define P pair<int,int>
    auto ask = [](vector<int> a)->ll{
        cout<<"? "; for(int x:a) cout<<x; cout<<endl;
        cout.flush();
        ll x; cin>>x;
        return x;
    };
    vector<int> a(m, 0);
    vector<P> e(m);
    fors(i,0,m){
        a[i] = 1;
        int w = ask(a); e[i] = P(w, i);
        a[i] = 0;
    }
    sort(all(e));
    ll cur = 0;
    for(auto[w,id]:e){
        a[id] = 1;
        ll val = ask(a);
        if(val != cur+w) a[id] = 0;
        else cur += w;
    }
    cout<<"! "<<cur<<endl;
    return 0;
}