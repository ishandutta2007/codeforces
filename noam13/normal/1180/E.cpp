#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
//#define abs(a) ((a)>0?a:-(a))
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;
const int MAXN=1e6+10;


struct Seg{
    vi a;
    vi maxSuf;
    int sz;
    vi r;
    Seg(vi ar){
        for(sz=1;sz<ar.size();sz*=2);
        a.resize(2*sz,0);
        maxSuf.resize(2*sz,0);
        r.resize(2*sz,-1);
        loop(i,0,ar.size()){
            a[i+sz]=ar[i];
            maxSuf[i+sz]=a[i+sz];
        }
        loop(i,0,sz){
            r[i+sz]=i;
        }
        for(int i=sz-1;i>0;i--){
            a[i]=a[i*2]+a[i*2+1];
            r[i]=r[2*i+1];
            maxSuf[i]=max(maxSuf[i*2]+a[i*2+1],maxSuf[i*2+1]);
        }
    }
    int sum(int l,int r){
        if (l>r) return 0;
        int ans=0;
        for(l+=sz,r+=sz;l<=r;l/=2,r/=2){
            if (l%2==1) ans+=a[l++];
            if (r%2==0) ans+=a[r--];
            if (l>=r) break;
        }
        return ans;
    }
    void Change(int dx,int i){
        i+=sz;
        a[i]+=dx;
        maxSuf[i]=a[i];
        for(i/=2;i>0;i/=2){
            a[i]=a[i*2]+a[i*2+1];
            maxSuf[i]=max(maxSuf[i*2]+a[i*2+1],maxSuf[i*2+1]);
        }
    }
    int q(){
        //cerr<<"PATH: ";
        int v=query(1);
        //cerr<<endl;
        return v;
    }
    int query(int cur){
        //cerr<<cur<<" ";
        if (maxSuf[cur]+sum(r[cur]+1,sz-1)<=0) return -1;
        if (cur>=sz){
            if (sum(cur-sz,sz-1)>0) return cur-sz;
            return -1;
        }
        if (maxSuf[cur*2+1]+sum(r[cur*2+1]+1,sz-1)>0) return query(cur*2+1);
        return query(cur*2);
    }
    void printTree(){
        int t=1;
        loop(i,1,sz*2){
            if (t==i) {
                cout<<endl;
                t*=2;
            }
            cout<<a[i]<<" ";
        }
        cout<<endl;
        t=1;
        loop(i,1,sz*2){
            if (t==i) {
                cout<<endl;
                t*=2;
            }
            cout<<maxSuf[i]<<" ";
        }
        cout<<endl<<endl;
    }
    void printPath(int i){
        cout<<"PATH OF "<<i<<" : ";
        for(i+=sz;i>0;i/=2) cout<<a[i]<<" ";
        cout<<endl;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vi cnt(MAXN,0);
    vi a(n),b(m);
    loop(i,0,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    loop(i,0,m){
        cin>>b[i];
        cnt[b[i]]--;
    }
    //loop(i,0,10) cout<<cnt[i]<<" ";
    //cout<<"hi"<<endl;
    Seg s(cnt);
    //s.printTree();
    int q; cin>>q;
    int x,i;
    loop(j,0,q){
        //s.printTree();
        cin>>x;
        if(x==1){
            cin>>i>>x; i--;
            s.Change(-1,a[i]);
            s.Change(1,x);
            a[i]=x;
        }
        else{
            cin>>i>>x; i--;
            s.Change(1,b[i]);
            s.Change(-1,x);
            b[i]=x;
        }
        cout<<s.q()<<endl;
    }
    return 0;
}
/*
3 5
3 2 8
1 2 8 1 1
4
1 3 3
1 2 2
2 2 10
1 1 5
*/