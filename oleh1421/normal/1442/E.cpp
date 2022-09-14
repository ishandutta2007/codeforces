#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
vector<int>g[N];
int a[N];
int n;
bool used[N];
int cnt[N];
int calc(){
    vector<set<pair<int,int> > >st;
    st.resize(3);
    for (int i=1;i<=n;i++){
        used[i]=false;
        cnt[i]=g[i].size();
        st[a[i]].insert({cnt[i],i});
    }
    int res=0;

    for (int it=0;!st[0].empty() || !st[1].empty() || !st[2].empty();it++){
        res++;
        int c=(it%2)*2;
        while (true){
            int x=(st[c].empty() ? 0 : (*st[c].begin()).second);
            if (x && cnt[x]<=1){
                used[x]=true;
                st[c].erase(st[c].begin());
                for (int to:g[x]){
                    if (!used[to]){
                        st[a[to]].erase({cnt[to],to});
                        cnt[to]--;
                        st[a[to]].insert({cnt[to],to});
                    }
                }
            } else {
                int x=(st[1].empty() ? 0 : (*st[1].begin()).second);
                if (x && cnt[x]<=1){
                    st[1].erase(st[1].begin());
                    used[x]=true;
                    for (int to:g[x]){
                        if (!used[to]){
                            st[a[to]].erase({cnt[to],to});
                            cnt[to]--;
                            st[a[to]].insert({cnt[to],to});
                        }
                    }
                } else {
                    break;
                }
            }
        }
    }
    return res;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) g[i].clear(),used[i]=false;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]==0) a[i]=1;
        else if (a[i]==1) a[i]=0;
    }
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res=calc();
    for (int i=1;i<=n;i++){
        used[i]=false;
        a[i]=2-a[i];
    }
    res=min(res,calc());
    cout<<res<<endl;

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}