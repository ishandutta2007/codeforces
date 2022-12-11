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
        int ans = 0;
        while(n--){
            int x; cin>>x; ans += x-1;
        }
        if(ans&1) cout<<"errorgorn"<<endl;
        else cout<<"maomao90"<<endl;
    }
    return 0;
}