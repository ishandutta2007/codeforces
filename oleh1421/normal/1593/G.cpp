//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N];
struct node{
    int val;
    int len;
    node(){
        val=len=0;
    }
    node(int x){
        len=1;
        val=x;
    }
};
inline node Merge(node A,node B){
    if (A.len==0) return B;
    if (B.len==0) return A;
    node C;
    if ((A.val+A.len-1)%2!=B.val){
        C.val=A.val;
        C.len=A.len+B.len;
    } else if (A.len<B.len){
        C.val=(B.val+A.len)%2;
        C.len=B.len-A.len;
    } else if (A.len>B.len){
        C.val=A.val;
        C.len=A.len-B.len;
    } else {
        C=node();
    }
    return C;
}
node t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=node(a[l]);
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
node get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return node();
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return Merge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    string s;cin>>s;
    int n=s.size();
    for (int i=1;i<=n;i++){
        char c=s[i-1];
        if (c=='(' || c==')') a[i]=0;
        else a[i]=1;
    }
    int q;cin>>q;
    build(1,1,n);
    for (int it=1;it<=q;it++){
        int l,r;cin>>l>>r;
        cout<<get(1,1,n,l,r).len/2<<'\n';
    }

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

//a b c
//a (b+c)/2 (b+c)/2
//(2*a+b+c)/4 (2*a+b+c)/4 (b+c)/2
//(2*a+b+c)/4 (2*a+3*b+3*c)/8 (2*a+3*b+3*c)/8
//(6*a+5*b+5*c)/16 (6*a+5*b+5*c)/16
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3

//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/