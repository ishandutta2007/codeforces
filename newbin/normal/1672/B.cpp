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
        string s; cin>>s;
        int ans = 1;
        if(s.back() != 'B') ans = 0;
        int a = 0;
        for(auto ch:s){
            if(ch =='A') a++;
            else a--;
            if(a < 0) ans = 0;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}