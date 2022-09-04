#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 210000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
const int MAX_N=1<<20;
int nnn,dat[2*MAX_N-1];
void init(int nn){
    nnn=1;
    while(nnn<nn) nnn*=2;
    for(int i=0;i<2*nnn-1;i++) dat[i]=INF;
}
void update(int k,int a){
    k+=nnn-1;dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}
int querry(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return INF;
    if(a<=l&&r<=b) return dat[k];
    int vl=querry(a,b,k*2+1,l,(l+r)/2);
    int vr=querry(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
}
int rmq(int a,int b){
    return querry(a,b,0,0,nnn);
}
main(){
    int n,q;
    cin>>n>>q;
    init(n);
    int a[N];
    int zr=-1;
    rep(i,n){
        cin>>a[i];
        if(a[i]==0) zr=i;
        if(a[i]==0&&i==0){
            while(1){
                i++;
                if(i==n) break;
                cin>>a[i];
                if(a[i])break;
            }
            if(i==n){
                cout<<"YES"<<endl;
                rep(j,n) cout<<q<<" ";
                return 0;
            }
            else{
                rep(j,i){update(j,a[i]);
                a[j]=a[i];}
            }
        }
        else if(a[i]==0){
            a[i]=a[i-1];
        }
        update(i,a[i]);
    }
    int s[N][2];
    rep2(i,0,q){
        s[i][0]=INF;
        s[i][1]=-1;
    }
    rep(i,n){
        if(s[a[i]][0]==INF) s[a[i]][0]=i;
        else s[a[i]][1]=i+1;
    }
    rep2(i,1,q){
        if(rmq(s[i][0],s[i][1])<i){
            cout<<"NO";return 0;
        }
    }
    if(s[q][0]==INF&&zr==-1){cout<<"NO";return 0;}
    else if(s[q][0]==INF&&zr>=0)a[zr]=q;
    cout<<"YES"<<endl;
    rep(i,n){
        cout<<a[i]<<" ";
    }

}