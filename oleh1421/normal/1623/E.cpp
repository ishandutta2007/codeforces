#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
char c[N];
char nxt[N];
int l[N],r[N];
vector<int>order;
void dfs1(int v){
    if (!v) return;
    dfs1(l[v]);
    order.push_back(v);
    dfs1(r[v]);
}
bool dbl[N];
int dfs2(int v,int k){
    if (!v) return 0;

    if (k==0) return 0;
    int ans=dfs2(l[v],k-1);
    if (ans){
        k--;
        k-=ans;
        dbl[v]=true;
        ans++;
        ans+=dfs2(r[v],k);
        return ans;
    } else {
//        cout<<c[v]<<" "<<nxt[v]<<endl;
        if (nxt[v]<c[v]){
            return 0;
        }
        else {
//            cout<<"OOOOOK"<<endl;
            k--;
            dbl[v]=true;
            return dfs2(r[v],k)+1;
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    dfs1(1);
    nxt[order.back()]=0;
    for (int i=(int)order.size()-2;i>=0;i--){
        if (c[order[i]]==c[order[i+1]]) nxt[order[i]]=nxt[order[i+1]];
        else nxt[order[i]]=c[order[i+1]];
    }
    k=dfs2(1,k);
    string ans="";
    for (int v:order){
        ans+=c[v];
        if (dbl[v]) ans+=c[v];
    }
    cout<<ans<<endl;

    return 0;
}
///daarkkcyan