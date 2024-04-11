#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
using namespace std;
const int N=310000;
int n,k;
int a[N];
map<int,vector<int> >g;
int TOT=1;
int t[N*35][2];
int ind[N*35];
void add(int x,int I){
    int v=1;
    for (int i=29;i>=0;i--){
        int cur=(x>>i)%2;
        if (!t[v][cur]) t[v][cur]=++TOT;
        v=t[v][cur];
        ind[v]=I;
    }
}
void clr(int v){
    if (!v) return;
    ind[v]=0;
    clr(t[v][0]);
    clr(t[v][1]);
    t[v][0]=t[v][1]=0;
}
int mx(int x){
    int v=1;
    for (int i=29;i>=0;i--){
        int cur=((x>>i)+1)%2;
        if (!t[v][cur]) t[v][cur]=++TOT;
        if (ind[t[v][cur]]==0) cur^=1;
        v=t[v][cur];
    }
    return ind[v];
}
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (k==0){
        cout<<n<<endl;
        for (int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    int gr=-1;
    for (int i=0;i<30;i++){
        if (k&(1<<i)){
            gr=i;
        }
    }
    for (int i=1;i<=n;i++){
        int mask=a[i];
        for (int j=0;j<=gr;j++){
            if (mask&(1<<j)) mask^=(1<<j);
        }
        g[mask].push_back(i);
    }
    vector<int>ans;

    for (auto cur:g){
//        cout<<"OK"<<endl;
        vector<int>A,B;
        for (int i:cur.second){
            if (a[i]&(1<<gr)) {
                B.push_back(i);
            }else {
                A.push_back(i);
            }
        }
        if (A.size()>B.size()) swap(A,B);
        for (int i:A){
            int x=(a[i]&((1<<gr)-1));
            add(x,i);
        }

        bool ok=false;
        if (!A.empty()){
            for (int i:B){
                int x=(a[i]&((1<<gr)-1));
                int y=mx(x);
                if ((a[i]^a[y])>=k){
                    ans.push_back(i);
                    ans.push_back(y);
                    ok=true;
                    break;
                }
            }
        }
        if (!ok) ans.push_back(cur.second.back());
        TOT=1;
        clr(1);
    }
    if (ans.size()<=1){
        cout<<-1<<endl;
    } else {
        cout<<ans.size()<<endl;
        for (int i:ans) cout<<i<<" ";
        cout<<endl;
    }


}
int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;

}

/**

2 1073741823
1073741823 0
**/