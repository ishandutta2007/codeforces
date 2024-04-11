#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e3+9;
int a[N][N];
int L[N][N],R[N][N],U[N][N],D[N][N],n,m;
void updLR(const int &i){
	L[i][0]=0;
    rep(j,1,m+1)if(!a[i][j])L[i][j]=j;
    else L[i][j]=L[i][j-1];
    R[i][m+1]=m+1; 
    per(j,1,m+1)if(!a[i][j])R[i][j]=j;
    else R[i][j]=R[i][j+1];
}
void updUD(const int &j){
    U[0][j]=0;
    rep(i,1,n+1)if(!a[i][j])U[i][j]=i;
    else U[i][j]=U[i-1][j];
    D[n+1][j]=n+1;
    per(i,1,n+1)if(!a[i][j])D[i][j]=i;
    else D[i][j]=D[i+1][j]; 
}
int ans;
void solveU(const int &x,const int &y){
    int l=L[x][y]+1,r=R[x][y]-1;
    for(int i=x,h=1;i;--i,++h){
        l=max(L[i][y]+1,l),r=min(R[i][y]-1,r);
        if(l>r)break;
        ans=max(ans,(r-l+1)*h);
    }
}

void solveD(const int &x,const int &y){
    int l=L[x][y]+1,r=R[x][y]-1;
    for(int i=x,h=1;i<=n;++i,++h){
        l=max(L[i][y]+1,l),r=min(R[i][y]-1,r);
        if(l>r)break;
        ans=max(ans,(r-l+1)*h);
    }
}
void solveL(const int &x,const int &y){
    int l=U[x][y]+1,r=D[x][y]-1;
    for(int i=y,h=1;i<=m;++i,++h){
        l=max(U[x][i]+1,l),r=min(D[x][i]-1,r);
        if(l>r)break;
        ans=max(ans,(r-l+1)*h);
    }
}
void solveR(const int &x,const int &y){
    int l=U[x][y]+1,r=D[x][y]-1;
    for(int i=y,h=1;i;--i,++h){
        l=max(U[x][i]+1,l),r=min(D[x][i]-1,r);
        if(l>r)break;
        ans=max(ans,(r-l+1)*h);
    }
}
int main(){
    int T;
    T=1;
    rep(Tcase,1,T+1){
        int q;
        scanf("%d%d%d",&n,&m,&q);
        rep(i,1,n+1){
            rep(j,1,m+1)scanf("%d",&a[i][j]);
            updLR(i);
        }
        rep(j,1,m+1){
            updUD(j);
        }
    //    printf("Case #%d:\n",Tcase);
        while(q--){
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            if(op==1){
                a[x][y]^=1;
                updLR(x);
                updUD(y);
            }
            else{
                if(!a[x][y]){
                    puts("0");
                    continue;
                }
                ans=0;
                solveU(x,y);
                solveD(x,y);
                solveL(x,y);
                solveR(x,y);
                printf("%d\n",ans);
            }
        }
    }
} 
/*
1
10 9 2
#########
####..###
#########
####.####
###..####
.###.####
#.###.###
###.#####
#########
#########
2 9 8
2 1 8
*/