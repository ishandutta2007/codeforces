#include <iostream>

int dp[501][501];
bool c[501][501];

int data[501];

int min(int a,int b){ return a>b?b:a; }

int work(int l,int r) {
    if(l>r) return 0;
    if(l==r) return 1;
    int& ret=dp[l][r];
    if(c[l][r]) return ret;
    c[l][r]=1;
    int i;
    ret=1+work(l+1,r);
    if(data[l]==data[l+1]) ret=min(ret,1+work(l+2,r));
    for(i=l+2;i<=r;++i){
        if(data[i]==data[l]){
            ret=min(ret,work(l+1,i-1)+work(i+1,r));
        }
    }
    return ret;
}

int main()
{
    int n;
    std::cin>>n;
    int i;
    for(i=0;i<n;++i) std::cin>>data[i];
    std::cout<<work(0,n-1);
    return 0;
}