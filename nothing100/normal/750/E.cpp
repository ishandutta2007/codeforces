#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1000000000
using namespace std;
int n,q;
struct tree{
    int a[5][5];
}tr[1000000];
string s;
void csh(tree &x){
    for (int i=0;i<5;i++)
    for (int j=0;j<5;j++) x.a[i][j]=inf;
}
tree he(tree x,tree y){
    tree z;
    csh(z);
    for (int k=0;k<5;k++)
    for (int i=0;i<5;i++)
    for (int j=0;j<5;j++) z.a[i][j]=min(z.a[i][j],x.a[i][k]+y.a[k][j]);
    return z;
}
void debug(tree x){
    for (int i=0;i<5;i++)
    for (int j=0;j<5;j++) printf("%d%c",x.a[i][j],j==4?'\n':' ');
    printf("\n");
}
void build(int now,int l,int r){
    if (l==r){
        csh(tr[now]);
        for (int i=0;i<5;i++) tr[now].a[i][i]=0;
        if (s[l-1]=='2'){
            tr[now].a[0][0]=1;
            tr[now].a[0][1]=0;
        }
        else if (s[l-1]=='0'){
            tr[now].a[1][1]=1;
            tr[now].a[1][2]=0;
        }
        else if (s[l-1]=='1'){
            tr[now].a[2][2]=1;
            tr[now].a[2][3]=0;
        }
        else if (s[l-1]=='6'){
            tr[now].a[3][3]=1;
            tr[now].a[4][4]=1;
        }
        else if (s[l-1]=='7'){
            tr[now].a[3][3]=1;
            tr[now].a[3][4]=0;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build((now<<1)+1,mid+1,r);
    tr[now]=he(tr[now<<1],tr[(now<<1)+1]);
}
tree get(int now,int l,int r,int x,int y){
    if (l>=x&&r<=y) return tr[now];
    if (r<x||l>y){
        tree tmp;
        csh(tmp);
        for (int i=0;i<5;i++) tmp.a[i][i]=0;
        return tmp;
    }
    int mid=(l+r)>>1;
    return he(get(now<<1,l,mid,x,y),get((now<<1)+1,mid+1,r,x,y));
}
int main(){
    scanf("%d%d",&n,&q);
    cin>>s;
    build(1,1,n);
    for (int i=0;i<q;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        o=get(1,1,n,o,p).a[0][4];
        printf("%d\n",o==inf?-1:o);
    }
}