#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 300010;
const ll mod=998244353;
const ll inf=1e18;
vector<int>dv[N];
vector<int>add[N];
vector<int>Q[N];
int l[N],r[N];
struct BIT{
    int t[N];
    BIT(){
        for (int i=0;i<N;i++) t[i]=0;
    }
    vector<int>used;
    void upd(int pos,int x){
        pos=N-pos-1;
        used.push_back(pos);
        for (;pos<N;pos|=pos+1) t[pos]+=x;
    }
    int get(int pos){
        pos=N-pos-1;
        int res=0;
        for (;pos>=0;pos&=pos+1,pos--) res+=t[pos];
        return res;
    }
    void clr(){
        for (int pos:used){
            for (;pos<N;pos|=pos+1) t[pos]=0;
        }
        used.clear();
    }
};
BIT T;
int ans[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        Q[r[i]].push_back(i);
    }
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j+=i) dv[j].push_back(i);
    }
    for (int k=1;k<N;k++){
//        if (k>4) break;
        for (int i=0;i+2<dv[k].size();i++){
            T.upd(dv[k][i],(int)dv[k].size()-i-2);
//            cout<<k<<" "<<dv[k][i]<<" "<<(int)dv[k].size()-i-2<<endl;
        }
//        2/3+2/5
        if ((2*k)%3==0 && k%2==0){
            T.upd(k/2,1);
//            cout<<k/2<<" "<<1<<endl;
        }
        if ((2*k)%3==0 && (2*k)%5==0){
            T.upd((k*2)/5,1);
//            cout<<k/2<<" "<<1<<endl;
        }
        for (int j:Q[k]){
            ans[j]=T.get(l[j]);
        }

    }

    for (int i=1;i<=n;i++) {
        ll len=r[i]-l[i]+1;
        ll val=len*(len-1)*(len-2)/6;
        val-=ans[i];
        cout<<val<<'\n';
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
/**
1
8 86

**/