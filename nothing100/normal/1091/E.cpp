#include<bits/stdc++.h>
#define LL long long
#define mo 998244353
using namespace std;
int n,a[500050];
LL hz[500050],qz[500050],f_l[500050],b_l[500050],tmp[500050];
int cmp(int x,int y){return x>y;}
int main(){
    //freopen("A.in","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    qz[0]=a[0];
    for (int i=1;i<n;i++) qz[i]=qz[i-1]+a[i];
    for (int i=n-1;i>=0;i--) hz[i]=hz[i+1]+a[i];
    int tail=n-1;
    f_l[0]=0;
    for (int i=0;i<n;i++){
        while (tail>=0&&a[tail]<=i) tail--;
        f_l[i+1]=qz[i]-1LL*i*(i+1)-hz[max(tail+1,i+1)]-1LL*max(0,tail-i)*(i+1);
        if (f_l[i+1]>i+1){
            printf("-1\n");
            return 0;
        }
    }
    tail=n-1;
    LL tmpp=0;
    for (int i=0;i<n;i++){
        while (tail>=0&&a[tail]<=i) tail--;
        b_l[i]=tmpp-1LL*i*(i+1)-hz[max(tail+1,i)]-1LL*max(0,tail-i+1)*(i+1);
        b_l[i]=-b_l[i];
        tmpp=tmpp+a[i];
    }
    b_l[n]=n;
    for (int i=1;i<=n;i++) f_l[i]=max(f_l[i-1],f_l[i]);
    //for (int i=0;i<=n;i++) printf("%lld ",f_l[i]);
    for (int i=n;i>0;i--) b_l[i-1]=min(b_l[i],b_l[i-1]);
    //printf("\n");
    //for (int i=0;i<=n;i++) printf("%lld ",b_l[i]);
    int hans=0;
    tail=n;
    for (int i=0;i<=n;i++){
        while (tail>0&&a[tail-1]<i) tail--;
        if (i>=f_l[tail]&&i<=b_l[tail]&&(qz[n-1]+i)%2==0){
            printf("%d ",i);
            hans=1;
        }
    }
    if (hans==0) printf("-1\n");
}