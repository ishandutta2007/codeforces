#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
ll exgcd(ll a,ll b,ll& x,ll &y){
	if(b==0) {
		x=1;y=0;
		return a;
	}
	ll x1,y1;
	ll ans=exgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-a/b*y1;
	return ans;
}
int main()
{
	long long n, p, w, d;
	ll x, y;
	cin>>n>>p>>w>>d;
	if(w < d)
        swap(w, d);
	ll g = exgcd(w,d, x, y);
	if(p%g != 0){
        printf("-1\n");return 0;
	}
	//x *= (p/g); y*= (p/g);
    //x 
    ll dx = d/g, dy = w/g;
    y %= dy;
    y = y * ((p/g)%dy)%dy;
    if(y < 0) y += dy;

    x = (p-y*d)/w;
    if(x >=0 && y >= 0 && x+y <= n) cout<<x<<" "<<y<<" "<<n-x-y<<endl;
    else cout<<-1<<endl;
}