#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long>node;
int main()
{
    int h;
    long long n;
    scanf("%d%I64d",&h,&n);
    long long num=n+(1LL<<h)-1;
    while(num>0){
        node.push_back(num);
        num=(num>>1);
    }
    long long ans=0;
    int h0=node.size(),L=1;
    for(int i=h0-1;i>=1;i--){
        if((L==1)&&(node[i]<<1)==node[i-1]){
            ans++;
            L=0;
        }
        else if((L==0)&&(node[i]<<1|1)==node[i-1]){
            ans++;
            L=1;
        }
        else{
            ans+=(1LL<<i);
        }
    }
    printf("%I64d",ans);
    return 0;
}