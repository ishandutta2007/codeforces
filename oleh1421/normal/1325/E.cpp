//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int mod=1000000007;
const int N=500010;
const int M=1000000;
int a[N];
int used[M+100];
int n;
int cn[N];
vector<int>g[N];
int d[N];
int d1[N];
int res=1000000001;
int used1[N];
int deep[N];
int pr[N];
int k;
void bfs(int s){
    queue<int>q;
    d[s]=0;
    q.push(s);
    vector<int>order={s};
    while (!q.empty()){
        int v=q.front();
        q.pop();

        for (auto to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                pr[to]=v;
                q.push(to);
                order.push_back(to);
            } else if (d1[to]==-1 && pr[v]!=to){
                d1[to]=d[v]+1;
            }
        }
    }

    for (auto x:order) {
        if (d1[x]!=-1) res=min(res,d[x]+d1[x]);
        d[x]=d1[x]=-1;
    }
}

int32_t main()
{

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=M;i++) used[i]=true;
    for (int i=2;i*i<=M;i++){
        for (int j=i*i;j<=M;j+=i) used[j]=false;
    }
    vector<int>p;
    for (int i=2;i<=M;i++) if (used[i]) {
            p.push_back(i);
            used[i]=p.size();
    }
    set<pair<int,int> >st;
    int need=0;
    for (int i=1;i<=n;i++){
        int x=a[i];
        int d=0;
        vector<int>v;
        while (p[d]*p[d]<=x){
            if (x%p[d]==0){
                int cn=0;
                while (x%p[d]==0){
                    x/=p[d];
                    cn++;
                }
                if (cn%2) v.push_back(d+1);
            }
            d++;
        }
        if (x>1) v.push_back(used[x]);
        if (v.empty()){
            cout<<1;
            return 0;
        }
        if (v.size()==1)  cn[v[0]]++;
        else {
//            if (st.find({v[0],v[1]})==st.end()){
                g[v[0]].push_back(v[1]);
                g[v[1]].push_back(v[0]);
//            }
//          cout<<v[0]<<" "<<v[1]<<endl;
            st.insert({v[0],v[1]});
            need++;
        }
    }
    if (need>st.size()){
        cout<<2;
        return 0;
    }
    k=p.size();
    for (int i=1;i<=k;i++){
        if (cn[i]>1){
            cout<<2;
            return 0;
        }
    }
//    for (int i=1;i<=k;i++){
//        if (!used1[i]) dfs(i,0,0);
//    }
    queue<int>q;
    for (int i=1;i<=k;i++){
        if (!cn[i]) d[i]=d1[i]=-1;
        else {
            d[i]=1;
            d1[i]=-1;
            q.push(i);
        }
    }
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                pr[to]=v;
                q.push(to);
            } else if (d1[to]==-1 && pr[v]!=to){
                d1[to]=d[v]+1;
            }
        }
    }

    for (int i=1;i<=k;i++){
        if (d1[i]!=-1) {
            res=min(res,d[i]+d1[i]);
//            if (d[i]+d1[i]==4) cout<<i<<" "<<d[i]<<" "<<d1[i]<<endl;
        }
    }
    for (int i=1;i<=k;i++){
        d[i]=d1[i]=-1;
    }
    for (int i=1;p[i]<=1000;i++) {
            bfs(i);
    }
    if (res>n) res=-1;
    cout<<res;

    return 0;
}
/*
1 2 3 4 5 6
2 3 5 7 11 13
1 2
2 3
3 6
6 5
1 4
4 5
4 3


6
15
65
143
14
77
35
*/