#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

int n,m,d;
vector<pair<int,string> > vec,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>d;
    if (d>4*n*m-2*n-2*m){
        cout<<"NO"<<endl;
        return 0;
    }
    n--,m--;
    cout<<"YES"<<endl;
    vec.pb({n,"D"});
    vec.pb({m,"R"});
    vec.pb({n,"U"});
    vec.pb({m,"L"});
    for (int i=1;i<=m;++i){
        vec.pb({1,"R"});
        vec.pb({n-1,"DLR"});
        vec.pb({1,"D"});
        if (i<m) vec.pb({n,"U"});
    }
    vec.pb({m,"L"});
    vec.pb({n,"U"});
    for (auto c:vec){
        if (c.first==0) continue;
        string s=c.second;
        if (d<=s.size()*c.first){
            int u=d/s.size();
            if (u) ans.pb({u,s});
            if (d%s.size()==1){
                ans.pb({1,"D"});
            }
            if (d%s.size()==2){
                ans.pb({1,"DL"});
            }
            break;
        }
        d-=s.size()*c.first;
        ans.pb(c);
    }
    cout<<ans.size()<<"\n";
    for (auto c:ans){
        cout<<c.first<<" "<<c.second<<endl;
    }

    return 0;
}