#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=600010;
struct node{
    int cnt;
    int a[3];
    int b[3];
    node(){
        cnt=0;
        a[0]=a[1]=a[2]=b[0]=b[1]=b[2]=0;
    }
};
node t[N*4];
int msk[N];
node Merge(node A,node B){
    node C;
    C.cnt=A.cnt+B.cnt;
    for (int i=0;i<3;i++){
        if (A.b[i] && B.a[i] && A.b[i]!=B.a[i]){
            C.cnt--;
            int a=A.b[i];
            int b=B.a[i];
            for (int j=0;j<3;j++){
                if (A.a[j]==a) A.a[j]=b;
                if (A.b[j]==a) A.b[j]=b;
                if (B.a[j]==a) B.a[j]=b;
                if (B.b[j]==a) B.b[j]=b;
            }
        }
    }
    for (int j=0;j<3;j++){
        C.a[j]=A.a[j];
        C.b[j]=B.b[j];
    }
    return C;
}
void build(int v,int l,int r){
    if (l==r){
        if (msk[l]==1+4){
            t[v].cnt=2;
            t[v].a[0]=t[v].b[0]=l*2-1;
            t[v].a[2]=t[v].b[2]=l*2;
        } else if (msk[l]==0){
            t[v].cnt=0;
        } else {
            for (int i=0;i<3;i++){
                t[v].a[i]=t[v].b[i]=((msk[l]>>i)%2)*l*2;
            }
            t[v].cnt=1;
        }
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
    int n;cin>>n;
    for (int i=0;i<3;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            if (c=='1') msk[j]|=(1<<i);
        }
    }
    build(1,1,n);
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        int l,r;cin>>l>>r;
        cout<<get(1,1,n,l,r).cnt<<endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
12
100101011101
110110010110
010001011101
1
1 12
**/