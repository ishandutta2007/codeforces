#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;
const int K=50;
int p[N],r[N];
int go[N];
void calc(int x){
    int last=x;
    for (int i=1;i<=K;i++) x=p[x];
    go[last]=x;
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>p[i];
        r[p[i]]=i;
    }
    for (int i=1;i<=n;i++) calc(i);
    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int x,y;cin>>x>>y;
            vector<int>v;
            int X=x;
            for (int it=1;it<=K;it++){
                v.push_back(X);
                X=r[X];
            }
            int Y=y;
            for (int it=1;it<=K;it++){
                v.push_back(Y);
                Y=r[Y];
            }
            swap(p[x],p[y]);
            swap(r[p[x]],r[p[y]]);
            for (int i:v) calc(i);

        } else {
            int x,k;cin>>x>>k;
            for (int i=1;i<=k/K;i++) x=go[x];
            for (int i=1;i<=k%K;i++) x=p[x];
            cout<<x<<endl;

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M