#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
void init()
{
    ll c[3]={0};
    for(int i=1;i<=100000;i++)
    {
        c[(i-1)%3]++;
        vec.push_back(c[0]*c[1]+c[1]*c[2]+c[2]*c[0]);
    }
}
int solve()
{
    int n;
    scanf("%d",&n);
    int res=lower_bound(vec.begin(),vec.end(),(n+1)/2)-vec.begin()+1;
    return 0*printf("%d\n",res);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}