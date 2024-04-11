#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vi sz(n); 
    //map<int, int> mp;
    vi hist(k);
    loop(i,0,n) {
        cin>>sz[i]; sz[i]--;
        hist[sz[i]]++;
    }
    /*vii hist;
    for(auto p:mp) hist.pb({p.x,p.y});
    reverse(all(hist));*/
    vi cond(k);
    loop(i,0,k) cin>>cond[i];
    //cout<<"MINI: "; loop(i,0,k) cout<<mini[i]<<" "; cout<<endl;
    vvi ans;
    int cur = 0;
    loopr(i,0,k){
        if (i!=k-1 && cond[i]>cond[i+1]) cur = 0;
        for(int &v=hist[i];v;){
            if (cur>=ans.size()) ans.pb(vi(0));
            int space = cond[i] - ans[cur].size();
            if (space>0) ans[cur].pb(i), v--;
            else cur++;
        }

    }
    /*loop(j,0,INF){
        vi cur;
        for(auto& p:hist){
            int i = p.x;
            int amt = min(int(mini[i]-cur.size()), p.y);
            if (cur.size()>=mini[0]) break;
            //cout<<"I="<<i<<": "<<mini[i]<<" "<<amt<<endl;
            loop(j,0,amt) cur.pb(i+1);
            p.y -= amt;
        }
        vii next;
        for(auto p:hist){
            if (p.y) next.pb(p);
        }
        hist = next;
        if (cur.size()) ans.pb(cur);
        else break;
    }*/
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v.size()<<" ";
        for(auto x:v) cout<<x+1<<" "; 
        cout<<endl;
    }
    /*int ans = 0;
    loop(i,0,k){
        if (hist[i]==0) continue;
        int limit = (hist[i] +cond[i])/ cond[i];
    }*/
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
4 3
1 2 2 3
4 1 1


*/