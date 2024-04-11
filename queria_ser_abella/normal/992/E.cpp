#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define mod 1000000007
#define debug 
using namespace std;

ll T[4*maxn];
ll mai[4*maxn];

inline void upd(int ini,int fim,int p,int pos,int val){
    if(ini > pos || fim < pos) return;
    if(ini == fim){
        T[p] = mai[p] = val;
        return;
    }
    int mid = (ini+fim)/2;
    upd(ini,mid,2*p,pos,val);
    upd(mid+1,fim,2*p+1,pos,val);
    T[p] = T[2*p] + T[2*p+1];
    mai[p] = max(mai[2*p],mai[2*p+1]);
}

inline ll qry(int ini,int fim,int p,int l,int r){
    if(ini > r || fim < l) return 0;
    if(ini >= l && fim <= r) return T[p];;
    int mid = (ini+fim)/2;
    return qry(ini,mid,2*p,l,r) + qry(mid+1,fim,2*p+1,l,r);
}

inline int search(int ini,int fim,int p,int l,int r,ll k){
    if(ini > r || fim < l) return maxn;
    int mid = (ini+fim)/2;
    //if(ini >= l && fim <= r){
    if(mai[p] < k) return maxn;
    if(ini == fim)
        return ini;
    int a = search(ini,mid,2*p,l,r,k);
    if(a < maxn) return a;
    return search(mid+1,fim,2*p+1,l,r,k);
   
}

int v[maxn];

char ch;
inline void rd(int &num){
    num = 0;
    while((ch=getchar()) >= '0')
        num  = 10*num+ch-'0';
}

int main(){
    
    int n,q;
    rd(n);
    rd(q);
    for(int i=0;i<n;i++){
        int a;
        rd(a);
        v[i] = a;
        upd(0,n-1,1,i,a);
    }
    while(q--){
        int pos, val;
        rd(pos);
        rd(val);
        pos--;
        v[pos] = val;
        upd(0,n-1,1,pos,val);
        if(v[0] == 0){
            printf("1\n");
            continue;
        }
        ll S = v[0];
        int cur = 0;
        int foi = 0;
        while(cur < n-1 && S < 1e15){
            int id = search(0,n-1,1,cur+1,n-1,S);
       //     debug("search %d S %lld -> %d\n",cur,S,id);
            if(id == maxn) {
                break;
            }
        //    debug("%lld != %d\n",qry(0,n-1,1,0,id-1)  , v[id]);
            if(qry(0,n-1,1,0,id-1)  == v[id]){
                printf("%d\n",id+1);
                foi = 1;
                break;
            }
            S = qry(0,n-1,1,0,id);
            cur = id;
        }
        if(foi == 0)
            printf("-1\n");
    }
    
}