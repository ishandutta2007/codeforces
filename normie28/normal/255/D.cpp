#include <bits/stdc++.h>
using namespace std;
int n,x,y,t[10];
long long cc;
bool check(long long c){
    long long g=2*c*c+2*c+1;
    if(y-c<0)g-=(c-y)*(c-y);
    if(x-c<0)g-=(c-x)*(c-x);
    if(y+c>=n)g-=(y+c-n+1)*(y+c-n+1);
    if(x+c>=n)g-=(x+c-n+1)*(x+c-n+1);
    if(c-x-y-1>0)g+=(c-x-y)*(c-x-y-1)/2;
    if(c-n+x-y>0)g+=(c-n+x+1-y)*(c-n+x-y)/2;
    if(c-x-n+y>0)g+=(c-x-n+y+1)*(c-x-n+y)/2;
    if(c-2*n+x+y+1>0)g+=(c-2*n+x+y+1)*(c-2*n+x+y+2)/2;
    if(g<cc)return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y>>cc;
    x--;
    y--;
    if(cc==1){
        cout<<"0\n";
        return 0;
    }
    long long lb=0,ub=2e9;
    while(ub-lb>1){
        long long mid=(ub+lb)>>1;
        if(check(mid))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
}