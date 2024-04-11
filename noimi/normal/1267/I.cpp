#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define vec vector<int>
 
vector<vector<int>> mem;
vec ord;
int ask(int x,int y){
    if(mem[x][y])return mem[x][y]-1;
    cout<<"? "<<x<<" "<<y<<endl;
    cout.flush();
    char c;cin>>c;
    int res = (c=='<');
    mem[x][y]=res+1;
    mem[y][x]=(1-res)+1;
    return res;
}
main(){
    int t; cin>>t;
    while(t--){
        vector<int> w,l;
        int n; cin>>n;
        mem=vector<vector<int>>(n*2+2,vector<int>(n*2+2));
        rep(i,n){
            if(ask(i*2+1,i*2+2)){
                w.pb(i*2+2);l.pb(i*2+1);
            }
            else{
                w.pb(i*2+1);l.pb(i*2+2);
            }
        }
        vec cnt(n);
        rep(i,n)rep2(j,i+1,n-1){
            if(ask(l[i],l[j])){
                cnt[j]++;
            }
            else cnt[i]++;
        }
        vec inv(n);
        rep(i,n)inv[cnt[i]]=l[i];
        bool end=true;
        rep(i,n){
            if(i==n-1){
                end=false;
                break;
            }
            int now=inv[i];
            int num=n-1-i;
            queue<int> q;
            for(auto e:w){
                if(ask(now,e))num++;
                else q.push(e);
            }
            if(num==n || num==n-1){
                cout<<"!"<<endl;
                cout.flush();
                break;
            }
            bool is_end=false;
            while(!q.empty()){
                // bool is_end=false;
                now=q.front();q.pop();
                num=0;
                rep2(e,1,n*2){
                    if(e==now)continue;
                    if(ask(now,e))num++;
                }
                if(num==n||num==n-1){
                    is_end=true;
                    cout<<"!"<<endl;
                    cout.flush();
                    break;
                }
            }
            if(is_end)break;
        }
        if(!end){
            vec next;
            int tmp=inv[n-1];
            rep(i,n){
                if((tmp-1)/2==(w[i]-1)/2)continue;
                next.pb(w[i]);
            }
            vec cnt2(n-1);
            rep(i,n-1){
                rep2(j,i+1,n-2){
                    if(ask(next[i],next[j]))cnt2[i]++;
                    else cnt2[j]++;
                }
            }
            int lose;
            rep(i,n-1)if(cnt2[i]==n-2)lose=next[i];
            int p;
            if(ask(lose,tmp))p=lose;
            else p=tmp;
            rep2(i,1,n*2){
                if(i==p)continue;
                if((tmp-1)/2==(i-1)/2)continue;
                ask(p,i);
            }
            cout<<"!"<<endl;
            cout.flush();
        }
    }
}