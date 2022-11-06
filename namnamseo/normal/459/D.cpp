#include <cstdio>
#include <algorithm>
#define S 1000010

int n;
int left [S];
int right[S];
int convert[S];
int cn;
int count[S];
int data[S];
int bit[S];

int finder(int x){
    int l=0, r=cn, m;
    /// convert[l] <= x < convert[r];
    while(l+1!=r){
        m=(l+r)>>1;
        if(convert[m]<=x) l=m;
        else r=m;
    }
    return l;
}

void update(int pos,int val){
    while(pos<=S){
        bit[pos]+=val;
        pos += (pos & (-pos));
    }
}

int sum(int x){
    int ret = 0;
    while(x){
        ret+=bit[x];
        x&=(x-1);
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) {
        scanf("%d",data+i);
        convert[i]=data[i];
    }
    std::sort(convert,convert+n);
    cn=std::unique(convert,convert+n)-convert;
    convert[cn]=2147483600;
    for(i=0;i<n;++i){
        data[i]=1+finder(data[i]);
    }
    for(i=0;i<n;++i){
        count[data[i]]++;
        left[i]=count[data[i]];
    }
    for(i=0;i<n;++i){
        right[i]=count[data[i]]-left[i]+1;
    }
    int tmp;
    long long ans = 0;
    for(i=n-2;0<=i;--i){
        tmp=right[i+1];
        update(tmp,1);
        ans=ans+sum(left[i]-1);
    }
    printf("%I64d\n",ans);
    return 0;
}