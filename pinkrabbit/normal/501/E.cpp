#include<cstdio>
#include<cstring>
#define N 100000
#define LL long long
using namespace std;
LL a[N+5];
LL cnt[N+5];
LL jud[N+5];
LL n,l,r,single,sum;
int main(void){
    scanf("%I64d",&n);
    for(LL i=0;i<n;++i){
        scanf("%I64d",a+i);
        cnt[a[i]]++;
    }
    for(LL i=0;i<=n;++i)
        if(cnt[i]&1)single++;
    if(single>1){
        printf("0\n");
        return 0;
    }
    for(l=0;l<=(n>>1);++l){
        if(a[l]==a[n-1-l])cnt[a[l]]-=2;
        else break;
    }
    r=n-1-l;
    if(l>=r){
        printf("%I64d\n",n*(n+1)/2);
        return 0;
    }
    LL left=r;
    for(;left>=l;--left){//(l,left)
        jud[a[left]]++;//(left,r)
        if(jud[a[left]]*2>cnt[a[left]]){
            if(left>((n-1)>>1))break;//
            if(a[left]!=a[n-1-left])break;//
            if(cnt[a[left]]%2==0&&left==n-1-left)break;//
        }
    }
    sum+=(r-left)*(l+1);
    memset(jud,0,sizeof(jud));
    int right=l;
    for(;right<=r;++right){
        jud[a[right]]++;
        if(jud[a[right]]*2>cnt[a[right]]){
            if(right<((n-1)>>1))break;
            if(a[right]!=a[n-1-right])break;
            if(cnt[a[right]]%2==0&&right==n-1-right)break;
        }
    }
    sum+=(right-l)*(n-r);
    sum+=(n-r)*(l+1);
    printf("%I64d\n",sum);
}