#include <bits/stdc++.h>
#define maxn 200200
#define mod 1000000007
#define maxl 5111111
#define pb push_back
#define debug 
typedef long long ll;
using namespace std;

struct rmq {
    int v[maxn+100];
    int T[4*maxn+100];
    
    void upd(int ini,int fim,int p,int pos,int val){
        if(pos > fim || pos < ini)
            return;
        if(ini == fim){
            T[p] = val;
            return;
        }
        int mid = (ini+fim)/2;
        upd(ini,mid,2*p,pos,val);
        upd(mid+1,fim,2*p+1,pos,val);
        T[p] = max(T[2*p],T[2*p+1]);
    }
    
    void bd(int a){
        for(int i=0;i<maxn;i++)
            v[i] *= a;
        for(int i=0;i<maxn;i++)
            upd(0,maxn-1,1,i,v[i]);
    }
    int qr(int ini,int fim,int p,int l,int r){
        if(ini > r || fim < l)
            return -1e9;
        if(ini >= l && fim <= r)
            return T[p];
        int mid = (ini+fim)/2;
        int A = qr(ini,mid,2*p,l,r);
        int B = qr(mid+1,fim,2*p+1,l,r);
        return max(A,B);
    }
    
    int qry(int a,int b){
       // int y = -1e9;
        //for(int i=a;i<=b;i++) y = max(y,v[i]);
        int x = qr(0,maxn-1,1,a,b);    
        debug("qry %d~%d = %d\n",a,b,x);
        return x;
        
    }
};

char ch;
inline void rd(int &x){
    x = 0;
    while((ch=getchar()) >= '0')
        x = 10*x+ch-'0';
}

int sieve[maxl];

vector<int> pr[maxn];
int v[maxn];
int dv[230][maxn];

int best[8][maxl];

int main(){
    for(int i=2;i<maxl;i++)
        if(sieve[i] == 0){
            sieve[i] = i;
            for(int j=i;j<maxl;j+=i)
                sieve[j] = i;
        }
        
    int n,q;

    rd(n);
    rd(q);
   // scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
     //   scanf("%d",v+i);
        rd(v[i]);
        int aux = v[i];
        int num = 1;
        while(aux != 1){
            int p = sieve[aux];
            int cnt = 0;
            while(aux % p == 0){
                aux /= p;
                cnt++;
            }
            if(cnt%2 == 1)
                pr[i].pb(p), num *= p;
        }
        v[i] = num;
    }
    
    rmq R[1][15];
    
    for(int i=0;i<15;i++)
        for(int j=0;j<n;j++)
            R[0][i].v[j] = -1;//, R[1][i].v[j] = n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<pr[i].size());j++){
            dv[j][i] = 1;
            for(int k=0;k<pr[i].size();k++)
                if(j & (1<<k))
                    dv[j][i] *= pr[i][k];
        }
    }
    
    for(int i=0;i<maxl;i++)
        for(int j=0;j<=7;j++)
            best[j][i] = -1;
    
    for(int i=0;i<n;i++){
        debug("i %d\n",i);
        for(int j=0;j<(1<<pr[i].size());j++){
            int tira = pr[i].size()-__builtin_popcount(j);
            int num = dv[j][i];
            int op;
            debug("num %d tira %d\n",num,tira);
            for(int k=0;k<=7&&k+tira<15;k++){
                op = k + tira;
                R[0][op].v[i] = max(R[0][op].v[i], best[k][num]);
            }
        }
        for(int j=0;j<(1<<pr[i].size());j++){
           int tira = pr[i].size()- __builtin_popcount(j);
           int num = dv[j][i]; 
           best[tira][num] = i;
        }
    }
    
    for(int j=0;j<n;j++)for(int i=0;i<3;i++)
        
            debug("R 0 %d . v[%d] = %d\n",i,j,R[0][i].v[j]);
    
    
    
    for(int i=0;i<15;i++){
        R[0][i].bd(1);
     //   R[1][i].bd(-1);
    }
    
    while(q--){
        int a,b;
        rd(a);
        rd(b);
        a--;
        b--;
        //scanf("%d%d",&a,&b), a--, b--;
        for(int i=0;i<20;i++){
            if(R[0][i].qry(a,b) >= a){
                printf("%d\n",i);
                break;
            } 
        }
    }
    
}