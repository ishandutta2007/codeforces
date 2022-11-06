#include <cstdio>

int n,m,w;
int data[100010];

long long waters[100010];

bool check(long long minv){
    int i;
    for(i=0;i<n;i++) waters[i]=0;
    long long howmuch=0;
    long long to;
    long long current=0;
    for(i=0;i<n;i++){
        if(w<=i) current-=waters[i-w];
        if(data[i]+current<minv){
            to=minv-data[i]-current;
            current+=to;
            waters[i]=to; howmuch+=to;
        }
        if(howmuch > m) return false;
    }
    return howmuch <= m;
}

int main()
{
    scanf("%d%d%d",&n,&m,&w);
    int i;
    for(i=0;i<n;i++) scanf("%d",data+i);
    long long left=1, right=1000100001, mid; /// left : true, right : false
    while(left+1 != right){
        mid = (left+right)/2;
        if(check(mid)) left=mid;
        else right=mid;
    }
    printf("%I64d\n",left);
    return 0;
}