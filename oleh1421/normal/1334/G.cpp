#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
typedef uint64_t lll;
#define endl '\n'
using namespace std;
const int N=200010+63;
const int c=64;
struct BIT{
    lll bt[N/c+5];
    void st(int i){
        int d=i/c;
        int ost=i%c;
        bt[d]|=(1ull<<ost);
    }
    int get(int i){
        int d=i/c;
        int ost=i%c;
        return ((bt[d]>>ost)&1ull);
    }
};
BIT bt[30];
int p[30];
BIT res;
BIT rg;
BIT rg1;
void F(BIT &A, BIT &B, BIT &C,int j){
    for (int i=0;i<N/c;i++){
        rg.bt[i]=(B.bt[i]|C.bt[i]);
    }
    memset(rg1.bt,0,sizeof(rg1.bt));
    int ost=j%c;
    int d=j/c;
    for (int i=0;i<N/c-d;i++){
        rg1.bt[i]=((rg.bt[i+d]>>ost)^(rg.bt[i+d+1]<<(c-ost)));
    }
    for (int i=0;i<N/c;i++){
        A.bt[i]&=rg1.bt[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0;i<26;i++) cin>>p[i],p[i]--;
    string a="",b="";
    cin>>b>>a;
    for (int i=0;i<a.size();i++){
        bt[a[i]-'a'].st(i);
    }
    for (int i=0;i<N;i++){
        res.st(i);
    }
    for (int i=0;i<b.size();i++){
        F(res,bt[b[i]-'a'],bt[p[b[i]-'a']],i);
    }
    for (int i=0;i<a.size()-b.size()+1;i++){
        cout<<res.get(i);
    }
    return 0;
}