//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=15010;
const int Lg=30;
mt19937 rnd(time(NULL));
int p[N];
int ans[N];
int a[N];
int n;
int CNT=0;
int B[N];
int ask(vector<int>v){
    CNT++;
    for (int i=1;i<=n;i++) a[i]=0;
    for (int i:v){
        a[i]=1;
    }
    for (int i=1;i<=n;i++){
        if (a[i]) cout<<'T';
        else cout<<'F';
    }
    cout<<endl;
    int ans=0;
    for (int i=1;i<=n;i++){
            ans+=(a[i]==B[i]);
    }
    cin>>ans;
    if (ans==n) exit(0);

    return ans;
}
int tot=0;
int get(vector<int>v){
    return ((ask(v)+v.size()+tot-n)/2);
}
int b[N];
vector<int>s;
void rec1(vector<int>v,int cur){
    if (cur==v.size() || cur==0){
        for (int i=0;i<v.size();i+=2){
            s.push_back((cur/(int)v.size())*2);
        }
        return;
    }

    if (v.size()==2){
        s.push_back(cur);
        return;
    }

    int m=(((int)v.size()/2)/2)*2;
    vector<int>A,B;
    for (int i=0;i<v.size();i++){
        if (i<m) A.push_back(v[i]);
        else B.push_back(v[i]);
    }
    int L=get(A);
    rec1(A,L);
    rec1(B,cur-L);
}
void rec(vector<int>v){
    if (v.empty()) return;
    if (v.size()%2){
        ans[v.back()]=get({v.back()});
        v.pop_back();
        rec(v);
        return;
    }
    shuffle(v.begin(),v.end(),rnd);

    vector<int>A;
    vector<int>B;
    s.clear();

    rec1(v,get(v));
    for (int i=1;i<v.size();i+=2){
        int cur=s[i/2];
        if (cur==1){
            if (rnd()%2){
                A.push_back(v[i]);
                B.push_back(v[i-1]);
            } else {
                B.push_back(v[i]);
                A.push_back(v[i-1]);
            }
        } else {
            ans[v[i]]=ans[v[i-1]]=cur/2;
        }
    }
    rec(A);
    for (int i=0;i<B.size();i++){
        ans[B[i]]=(ans[A[i]]^1);
    }
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) B[i]=rnd()%2;
    for (int i=1;i<=n;i++) ans[i]=-1;
    vector<int>v;
    for (int i=1;i<=n;i++){
        v.push_back(i);

    }
    tot=ask(v);

    rec(v);
    for (int i=1;i<=n;i++){
        if (ans[i]) cout<<'T';
        else cout<<'F';
    }
    cout<<endl;
    int x;cin>>x;

//    cout<<CNT<<endl;
//    for (int i=1;i<=n;i++){
//        if (B[i]!=ans[i]) exit(2);
//    }
    ///int x;cin>>x;



}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
//    4
//    (6/16)*(3/4*2)+
//    1
//    1 1
//    1 2 1
//    1 3 3 1
//    1 4 6 4 1
//    (1/16)
//    (4/16)*


//    1+(6/16)*(6/4)+(1/16)*0+(1/16)*0+(8/16)*2
}

//x^2+x(m-1)-m-P=0
//
//x^2+x=m+x+P
//x^2=m+P
//1+P/(m+X)

/**
14 1
9 15 17 14 8 17 3 12 20 4 19 8 4 5
5 19 10 1 12 8 1 15 20 1 13 2 18 6
1 14 28

**/