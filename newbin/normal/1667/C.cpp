#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
#define P pair<int,int>
vector<P> ans;
void in(int x, int y){
    ans.pb(P(x,y));
}
int main(){
    int n; cin>>n;
    if(n == 1){
        cout<<1<<"\n"<<1<<" "<<1<<endl; return 0;
    }
    if(n % 3 == 0){
        int k = n/3-1;
        fors(i,1,k+1) in(i,k+1-i); k++; fors(i,1,k+1) in(n-k+i,n+1-i); in(k,k);
    }else{
        int k = n/3;
        fors(i,1,k+1) in(i,k+1-i); k++; fors(i,1,k+1) in(n-k+i,n+1-i);
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<" "<<y<<endl;
    return 0;
}