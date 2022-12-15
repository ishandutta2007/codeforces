#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define pb push_back
#define mod 1000000007

int n,k,lis[11];
long long cnt;
double ans;

void pro(int l,int r)
{
    while(l<r)
    {
        swap(lis[l],lis[r]);
        l++;r--;
    }
}
int cou()
{
    int cur=0;
    For(i,0,n-1) For(j,i+1,n) if(lis[i]>lis[j]) cur++;
    return cur;
}

void solve(int kk)
{
    //cout<<kk<<endl;
    if(kk==0) cnt+=cou();
    else{
    For(i,0,n) For(j,i,n)
    {
        pro(i,j);
        solve(kk-1);
        pro(i,j);
    }}
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n>>k;
    For(i,0,n) cin>>lis[i];
    ans=1.0;
    For(i,0,k) ans/=(n*(n+1)/2);
    cnt=0;
    solve(k);
    ans*=cnt;
    printf("%.11f",ans);
    return 0;
}