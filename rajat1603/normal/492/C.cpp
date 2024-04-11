#include<iostream>
#include<algorithm>
#include<cstdio>
#include<utility>
using namespace std;
int main(){
    long long n,r,avg;
    pair<long long,long long> a[100001];
    long long sum=0;
    cin>>n>>r>>avg;
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;//first has b and second has marks
        sum+=a[i].second;
    }
    long long req = (long long) n*avg;
    req-=sum;
    sort(a,a+n);
    int i=0;
    long long ans=0;
    while(req>0){
        long long x= min(req,r-a[i].second);
        ans += x * a[i].first;
        req -= x;
        i++;
    }
    printf("%I64d",ans);
}