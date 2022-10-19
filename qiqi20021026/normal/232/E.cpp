#include<bits/stdc++.h>

using namespace std;

#define N 505

int n,m,p,X1,Y1,X2,Y2;
char s[N];
bool a[N][N];
bitset<N> f[10][N][N],g[10][N][N];

int getint(){
    char ch; int sum=0,fh=1;
    for (ch=getchar();ch<'0' || ch>'9';ch=getchar()) fh=ch=='-'?-1:1;
    for (;ch>='0' && ch<='9';ch=getchar()) sum=sum*10+ch-'0';
    return sum*fh;
}

int work(int x,int l,int r,int Y1,int Y2){
    int mid=(l+r)>>1;
    if (Y1<=mid && mid<=Y2) return x;
    if (Y2<mid) return work(x+1,l,mid-1,Y1,Y2);
    else return work(x+1,mid+1,r,Y1,Y2);
}

void solve(int x,int l,int r){
    int mid=(l+r)>>1;
    if (l<mid) solve(x+1,l,mid-1);
    if (mid<r) solve(x+1,mid+1,r);
    for (int i=n;i>=1;i--) if (a[i][mid]){f[x][i][mid][i]=1; f[x][i][mid]|=f[x][i+1][mid];}
    for (int i=n;i>=1;i--)
        for (int j=mid-1;j>=l;j--)
            if (a[i][j]) f[x][i][j]|=f[x][i][j+1]|f[x][i+1][j];
    for (int i=1;i<=n;i++) if (a[i][mid]){g[x][i][mid][i]=1; g[x][i][mid]|=g[x][i-1][mid];}
    for (int i=1;i<=n;i++)
        for (int j=mid+1;j<=r;j++)
            if (a[i][j]) g[x][i][j]|=g[x][i][j-1]|g[x][i-1][j];
}

int main(){
    n=getint(); m=getint();
    for (int i=1;i<=n;i++){
        scanf("%s",s+1);
        for (int j=1;j<=m;j++) if (s[j]=='.') a[i][j]=1; else a[i][j]=0;
    }
    solve(0,1,m);
    p=getint();
    for (int i=1;i<=p;i++){
        X1=getint(); Y1=getint(); X2=getint(); Y2=getint();
        int k=work(0,1,m,Y1,Y2); puts((f[k][X1][Y1]&g[k][X2][Y2]).count()?"Yes":"No");
    }

    return 0;
}