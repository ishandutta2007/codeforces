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

string a,b,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>a>>b>>c;
        int n=a.size();
        for (int i=0;i<n;++i){
            if (a[i]==b[i]&&c[i]!=a[i]){
                cout<<"NO"<<"\n";
                goto cont;
            }
            if (a[i]!=b[i]&&c[i]!=a[i]&&c[i]!=b[i]){
                cout<<"NO"<<"\n";
                goto cont;
            }
        }
        cout<<"YES"<<"\n";
        cont:;
    }
    return 0;
}