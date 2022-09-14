#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define __int128_t ll
const int N=400010;
int a[N],b[N];
int inv[N];
//struct node{
//    int mn,mx,cmp;
//    node(){
//        mn=1;
//        mx=0;
//        cmp=-1;
//    }
//};
//node Merge(node A,node B){
//    if (A.cmp==-1) return B;
//    if (B.cmp==-1) return A;
//    A.mn=min(A.mn,B.mn);
//}
//int t[N];
//void upd(int n,int pos,int x){
//    for (;pos<=n;pos|=pos+1){
//        t[pos]=max(t[pos],x);
//    }
//}
//int get(int pos){
//    int mx=0;
//    for (;pos>=0;pos&=pos+1,pos--){
//        mx=max(mx,t[pos]);
//    }
//    return mx;
//}
//int dp[N];
int type[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int Mn=n+n+1;
    int Mx=0;
    for (int i=1;i<=n;i++){
        Mx=max(Mx,min(a[i],b[i]));
        Mn=min(Mn,max(a[i],b[i]));
    }
    if (Mx>Mn){
        cout<<-1<<endl;
        return;
    }
    vector<pair<pair<int,int>,int> >v;
    for (int i=1;i<=n;i++){
        if (a[i]>b[i]){
            swap(a[i],b[i]);
            inv[i]=1;
        }
        v.push_back({{a[i],b[i]},inv[i]});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        a[i+1]=v[i].first.first;
        b[i+1]=v[i].first.second;
        inv[i+1]=v[i].second;
    }
//    dp[0]=0;
//    upd(2*n,0,0);
//    for (int i=1;i<=n;i++){
//        dp[i]=get(b[i])+1;
//        upd(n+n,b[i],dp[i]);
//        if (dp[i]>2){
//            cout<<-1<<endl;
//            return;
//        }
//    }
    int mn=n+n+1;
    for (int i=1;i<=n;i++){
        mn=min(mn,b[i]);
//        cout<<b[i]<<" "<<inv[i]<<endl;
        if (mn==b[i]){
            type[i]^=1;
        }
    }
    int mx=0;
    for (int i=n;i>=1;i--){
        mx=max(mx,b[i]);
        if (mx==b[i]){
            type[i]^=2;
        }
    }
    for (int i=1;i<=n;i++){
        if (type[i]==0){
            cout<<-1<<endl;
            return;
        }
    }
    vector<pair<int,int> >u;
    vector<pair<pair<int,int>,int> >V;
    for (int i=n;i>=1;i--){
        if (type[i]==2){
            u.push_back({b[i],i});
            V.push_back({{u.size(),u.size()},inv[i]});
        }
        if (type[i]==1){
            pair<int,int>fnd={b[i],100000001};
            int L=upper_bound(u.begin(),u.end(),fnd)-u.begin()+1;

            if (L<=u.size()){
//                cout<<"SEG "<<L<<" "<<u.size()<<endl;
                V.push_back({{L,u.size()},(inv[i]^1)});
            }
        }
    }
    sort(V.begin(),V.end());
    int res=0;
    if (!V.empty()){
        int R=V[0].first.second;
        int cnt=1;
        int sum=V[0].second;
        for (int i=1;i<V.size();i++){
            if (V[i].first.first<=R) {
                sum+=V[i].second;
                R=max(R,V[i].first.second);
                cnt++;
            } else {
                res+=min(sum,cnt-sum);
                cnt=1;
                sum=V[i].second;
                R=V[i].first.second;
            }
        }
        res+=min(sum,cnt-sum);
    }
    cout<<res<<endl;

    return;

}

int32_t main()
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
5 5 100
4
5
4
3
1
OK
FAIL
OK
OK
OK
FAIL
OK

0 1 0 0 0

1
5 5 100
4
5
4
2
1

FAIL
FAIL
FAIL
OK
FAIL
OK
OK
FAIL
FAIL
FAIL
OK


! 10
**/