#include <cstdio>

char buf[1010];
int k;
int n;

bool palin(int l,int r){
    if(l>r) return true;
    return buf[l]==buf[r] && palin(l+1,r-1);
}

int main()
{
    scanf("%s%d",buf,&k);
    for(n=0;buf[n];++n);
    if(n%k){
        puts("NO");
    } else {
        int i;
        for(i=0;i<k;++i){
            if(!palin(i*n/k,i*n/k+n/k-1)) break;
        }
        if(i<k) puts("NO");
        else puts("YES");
    }
    return 0;
}