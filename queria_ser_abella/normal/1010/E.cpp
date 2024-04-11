#include <bits/stdc++.h>
#define pb push_back
#define maxn 100100
#define debug 
#define inf 1e6
using namespace std;

int T[5*maxn];

int sa, sb, sc;

void upd(int ini,int fim,int p,int pos,int val,int f=0){
    if(ini > pos || fim < pos)
        return;
    if(ini == fim){
        if(sc == 1){
            T[p] = min(T[p],val);
            if(f) T[p] = val;
        }
        else {
            T[p] = max(T[p],val);
            if(f) T[p] = val;
            
        }
        return;
    }
    int mid = (ini+fim)/2;
    upd(ini,mid,2*p,pos,val,f);
    upd(mid+1,fim,2*p+1,pos,val,f);
    if(sc == 1)
        T[p] = min(T[2*p],T[2*p+1]);
    else
        T[p] = max(T[2*p],T[2*p+1]);
}

int qry(int ini,int fim,int p,int l,int r){
    if(r < l || ini > r || fim < l){
        if(sc == 1)
            return inf;
        else
            return -inf;
    }
    if(ini >= l && fim <= r){
        return T[p];
    }
    int mid = (ini+fim)/2;
    int a = qry(ini,mid,2*p,l,r);
    int b = qry(mid+1,fim,2*p+1,l,r);
    if(sc == 1)
        return min(a,b);
    else
        return max(a,b);
}

int X[maxn];
int Y[maxn];
int Z[maxn];

int qx[maxn];
int qy[maxn];
int qz[maxn];

int inside(int a,int b,int c){
    return a <= b && b <= c;
}

struct ev {
    int x,y,z,tipo,id;
    ev(int x=0,int y=0,int z=0,int tipo=0,int id=0): x(x), y(y), z(z), tipo(tipo), id(id) {}
    bool operator<(ev comp){
        if(x != comp.x){
            if(sa == 1)
                return x < comp.x;
            else
                return x > comp.x;
        }
        return tipo < comp.tipo;
    }
}

E[2*maxn];

int ans[maxn];

int open[maxn];
int in(int a,int b,int c){
    assert(b <= c);
    return (a >= b && a <= c);
}

int main(){
    int n,m,k;
    int N = 100100;
    scanf("%*d%*d%*d%d%d%d",&n,&m,&k);
    int x1,x2,y1,y2,z1,z2;
    x1 = y1 = z1 = inf;
    x2 = y2 = z2 = -inf;
    for(int i=0;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x1 = min(x1,x);
        y1 = min(y1,y);
        z1 = min(z1,z);
        x2 = max(x2,x);
        y2 = max(y2,y);
        z2 = max(z2,z);
    }
    debug("%d %d\n",x1,x2);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",X+i,Y+i,Z+i);
        if(inside(x1,X[i],x2) && inside(y1,Y[i],y2) && inside(z1,Z[i],z2)){
            printf("INCORRECT\n");
            return 0;
        }
    }
    
    debug("x %d~%d\n",x1,x2);
    debug("y %d~%d\n",y1,y2);
    debug("z %d~%d\n",z1,z2);
    
    for(int i=0;i<k;i++){
        scanf("%d%d%d",&qx[i],&qy[i],&qz[i]);
        if(in(qx[i],x1,x2) && in(qy[i],y1,y2) && in(qz[i],z1,z2))
            open[i] = 1;
    }
    for(int i=0;i<8;i++){
        sa = ((i&1) == 1);
        sb = ((i&2) == 2);
        sc = ((i&4) == 4);
        int sz = 0;
        for(int j=0;j<m;j++){
            int xx = X[j], yy = Y[j], zz = Z[j];
            if(sa == 1 && xx < x1) continue;
            if(sb == 1 && yy < y1) continue;
            if(sc == 1 && zz < z1) continue;
            if(sa == 0 && xx > x2) continue;
            if(sb == 0 && yy > y2) continue;
            if(sc == 0 && zz > z2) continue;
            E[sz++] = ev(xx,yy,zz,0,0);
        }
        for(int j=0;j<k;j++){
            int xx = qx[j], yy = qy[j], zz = qz[j];
            if(i == 7)
                debug("was %d %d %d\n",xx,yy,zz);
            if(inside(x1,xx,x2)){
                if(sa == 1)
                    xx = x2;
                else
                    xx = x1;
            }
            else if(sa == 1 && xx < x1)
                continue;
            else if(sa == 0 && xx > x2)
                continue;
            if(inside(y1,yy,y2)){
                if(sb == 1)
                    yy = y2;
                else
                    yy = y1;
            }
            else if(sb && yy < y1)
                continue;
            else if(!sb && yy > y2)
                continue;
            if(inside(z1,zz,z2)){
                if(sc == 1)
                    zz = z2;
                else
                    zz = z1;
            }
            else if(sc && zz < z1)
                continue;
            else if(!sc && zz > z2)
                continue;
            if(i == 7)
                debug("+ %d %d %d\n",xx,yy,zz);
            E[sz++] = ev(xx,yy,zz,1,j);
        }
        sort(E,E+sz);
        if(sc == 1)
            for(int j=1;j<=N;j++)
                upd(1,N,1,j,inf,1);
        else
            for(int j=1;j<=N;j++)
                upd(1,N,1,j,-inf,1);
                
        for(int j=0;j<sz;j++){
            if(i == 1)
                debug("tipo %d x %d y %d z %d\n",E[j].tipo,E[j].x,E[j].y,E[j].z);
            if(E[j].tipo == 0)
                upd(1,N,1,E[j].y,E[j].z);
            else {
                int A;
                if(sb == 0)
                    A = qry(1,N,1,E[j].y,N);
                else
                    A = qry(1,N,1,1,E[j].y);
                if(i == 1 && E[j].id == 0)
                    debug("qry %d~%d = !!! %d\n",1,E[j].y,A);
                if(sc == 1)
                    if(A <= E[j].z){
                        ans[E[j].id] = 1;
                        if(E[j].id == 0) debug("foi %d %d \n",E[j].id,i);
                    }
                if(sc == 0)
                    if(A >= E[j].z){
                        ans[E[j].id] = 1;
                         if(E[j].id == 0) debug("foi %d %d A %d z %d\n",E[j].id,i,A,E[j].z);
                    }
            }
        }
        
    }
    
    printf("CORRECT\n");
    for(int i=0;i<k;i++){
        if(open[i]){
            printf("OPEN\n");
            continue;
        }
        if(ans[i])
            printf("CLOSED\n");
        else
            printf("UNKNOWN\n");
    }
        
    }