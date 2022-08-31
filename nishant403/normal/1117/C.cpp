#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
ll x1,y1,x2,y2,n;
ll h=0,v=0;

cin >> x1 >>y1 >> x2 >> y2 >> n;
char c;
vector<pair<ll,ll> > pos(n+1);

pos[0]={0,0};

f(i,n)
{
cin >> c;

if(c=='U') v++;
else if(c=='D') v--;
else if(c=='R') h++;
else h--;
    
pos[i+1]={h,v} ;    
}

x2-=x1;
y2-=y1;


ll r=100000000000001;
ll ans=r;
ll l=0;
ll mid;


while(l<=r)
{
    
 mid=(l+r)/2;
 
if(  abs( (mid/n)*(pos[n].first) +pos[mid%n].first -x2 )+abs( (mid/n)*pos[n].second +pos[mid%n].second  + -y2 )  > mid ) l=mid+1;
else
{
    ans=min(ans,mid);
    r=mid-1;
}

}

if(ans==100000000000001) cout << -1 ;
else cout << ans;

   
}