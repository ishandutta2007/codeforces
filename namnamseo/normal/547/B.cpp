#include <cstdio>

int mintree[524288];
int m=262144;

int n;

int min(int a,int b){ return a>b?b:a; }
int max(int a,int b){ return a>b?a:b; }

int rangeMin(int l,int r){
    int ret=2e9;
    l+=m; r+=m;
    while(l<=r){
        if(l==r){ret=min(ret,mintree[l]); break;}
        if(l&1)ret=min(ret,mintree[l++]);
        if((r+1)&1)ret=min(ret,mintree[r--]);
        l/=2; r/=2;
    }
    return ret;
}
int gijun;
int findLeftestMore(int left,int right){
    if(left==right) return left;
    int mid=(left+right)/2;
    if(rangeMin(left,mid)<gijun) return findLeftestMore(left,mid);
    else return findLeftestMore(mid+1,right);
}

int findRightestMore(int left,int right){
    if(left==right) return left;
    int mid=(left+right)/2;
    if(rangeMin(mid+1,right)<gijun) return findRightestMore(mid+1,right);
    else return findRightestMore(left,mid);
}

int maxarray[200010];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<2*m;++i) mintree[i]=2e9;
    for(i=1;i<=n;++i) scanf("%d",mintree+m+i);
    for(i=m-1;1<=i;--i) mintree[i]=min(mintree[i*2],mintree[i*2+1]);
    int lt, rt;
    for(i=1;i<=n;++i){
        gijun=mintree[i+m];
        if(i!=1 && rangeMin(1,i-1)<gijun) lt=findRightestMore(1,i-1)+1;
        else lt=1;
        if(i!=n && rangeMin(i+1,n)<gijun) rt=findLeftestMore(i+1,n)-1;
        else rt=n;
        rt=rt-lt+1;
        maxarray[rt]=max(maxarray[rt],gijun);
        //printf("From size 1 to %d : %d possible\n",rt,gijun);
    }
    //printf("Left %d Right %d\n",findLeftestMore(1,3),findRightestMore(5,n));
    maxarray[n+1]=1;
    for(i=n;i>=1;--i){
        maxarray[i]=max(maxarray[i],maxarray[i+1]);
    }
    for(i=1;i<=n;++i) printf("%d ",maxarray[i]);
    return 0;
}