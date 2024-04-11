#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define mid ((r+l)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1,mid+1,r
#define pb push_back
#define lowbit(x) (x&(-x))
#define all(x) x.begin(),x.end()
using namespace std;
int vis[1<<20];
int main(){
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        if(n == 4){
            if(k >= 3){
                cout<<-1<<endl; 
            }
            else if(k == 2){
                cout<<0<<" "<<1<<endl;
                cout<<2<<" "<<3<<endl;
            }else if(k == 1){
                cout<<0<<" "<<2<<endl;
                cout<<1<<" "<<3<<endl;
            }else if(k == 0){
                cout<<0<<" "<<3<<endl;
                cout<<1<<" "<<2<<endl;
            }
            continue;
        }
        fors(i,0,n) vis[i] = 0;
        if(k == 0){
            int s = n-1;
            for(int i = 0; i < n; ++i){
                if(vis[i]) continue;
                vis[i] = vis[s^i] = 1;
                printf("%d %d\n", i, s^i);
            }
        }else{
            #define P pair<int,int>
            vector<P> ans;
            int s = n-1;
            if(k == n-1){
                ans.pb(P(s,s-1)); vis[s] = vis[s-1] = 1;
                ans.pb(P(1, 3)); vis[1] = vis[3] = 1;
                ans.pb(P(s-3, 0)); vis[0] = vis[s-3] = 1;
                for(int i = 0; i < n; ++i){
                    if(vis[i]) continue;
                    vis[i] = vis[s^i] = 1;
                    ans.pb(P(i,s^i));
                }
            }else{
                ans.pb(P(s,k)); vis[s] = vis[k] = 1;
                ans.pb(P(s^k, 0)); vis[0] = vis[s^k] = 1;
                for(int i = 0; i < n; ++i){
                    if(vis[i]) continue;
                    vis[i] = vis[s^i] = 1;
                    ans.pb(P(i,s^i));
                }
            }
            for(auto p:ans) printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}