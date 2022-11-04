#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1000000007;
int cnt(int n,int k)
{
    int res=0;
    while(n>0)
    {
        res+=n;
        if(res>INF)return INF;
        n/=k;
    }
    return res;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int low=1,up=n;
    while(low<up)
    {
        int mid=low+(up-low)/2;
        if(cnt(mid,k)<n)low=mid+1;
        else up=mid;
    }
    printf("%d",low);
    return 0;
}