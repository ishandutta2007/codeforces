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
        vector<int> a(n);
        fors(i,0,n) cin>>a[i];
        vector<int> c;
        fors(i,0,n){
            int j = i; while(j+1<n&&a[j+1]==a[j])j++;
            if(i==j && c.size() == 0) continue;
            c.pb(j-i+1); i = j;
        }
        while(c.size() && c.back() == 1) c.pop_back();
        if(c.size() == 0){
            cout<<0<<endl;
        }else if(c.size() == 1){
            int x = c[0];
            if(x <= 2) cout<<0<<endl;
            else if(x <= 4) cout<<1<<endl;
            else cout<<x-3<<endl;
        }else{
            int x = 0; for(auto y:c) x += y;
            if(x <= 4) cout<<1<<endl;
            else cout<<x-3<<endl;
        }
    }
    return 0;
}