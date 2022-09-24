#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

LL n,c,x,y,t;

LL in(LL t) {
    LL cnt=0;
    if (x+y<=t) cnt+=x*y;
    else {
	cnt+=t*(t-1)/2;
	if (x<t) cnt-=(t-x)*(t-x-1)/2;
	if (y<t) cnt-=(t-y)*(t-y-1)/2;
    }
    return cnt;
}
LL space(LL t) {
    LL cnt=1;
    cnt+=min(x, t)+min(y, t);
    cnt+=in(t); x=n-x-1;
    cnt+=in(t); y=n-y-1;
    cnt+=min(x, t)+min(y, t);
    cnt+=in(t); x=n-x-1;
    cnt+=in(t); y=n-y-1;
    return cnt;
}
int main() {
    cin>>n>>x>>y>>c;
    x--; y--;
    LL l=-1, r=n*3, m;
    for (;r-l>1;) {
	m=(r+l)>>1;
	if (space(m)>=c) r=m;
	else l=m;
    }
    cout<<r<<endl;
    return 0;
}