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
        vector<int> a(n), b(n);
        fors(i,0,n) cin>>a[i];
        fors(i,0,n) cin>>b[i];
        map<int,int> cnt;
        int p = 0;
        int ok = 1;
        for(int i = 0; i < n; ++i){
            if(p >= n){
                if(b[i-1] == b[i] && cnt[b[i]] > 0){
                    cnt[b[i]]--; continue;
                }else{
                    ok = 0; break;
                }
            }
            if(a[p] == b[i]) {p++; continue;}
            else{
                if(i > 0 && b[i-1] == b[i] && cnt[b[i]] > 0){
                    cnt[b[i]]--; continue;
                }
                cnt[a[p]]++; p++; i--;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}