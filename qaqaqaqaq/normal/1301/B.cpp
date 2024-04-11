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

const int maxn=400007;
int n,t,a[maxn],l,r,val;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        val=0,l=1e9,r=0;
        cin>>n;
        for (int i=0;i<n;++i){
            cin>>a[i];
        }
        for (int i=0;i<n-1;++i){
            if (a[i]!=-1&&a[i+1]!=-1){
                val=max(val,abs(a[i+1]-a[i]));
            }
            else{
                if (a[i]==-1&&a[i+1]!=-1){
                    l=min(l,a[i+1]), r=max(r,a[i+1]);
                }
                if (a[i]!=-1&&a[i+1]==-1){
                    l=min(l,a[i]), r=max(r,a[i]);
                }
            }
        }
        cout<<max(val,(r-l+1)/2)<<" "<<(l+r)/2<<"\n";
    }
    return 0;
}