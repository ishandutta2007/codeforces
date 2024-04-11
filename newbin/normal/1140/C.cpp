#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 3e5 + 50;
#define P pair<ll>
priority_queue<ll,vector<ll>,greater<ll> > q;
ll sum = 0;
struct node{
	ll t,b;
	bool operator < (const node& x)const {return b > x.b;}
}e[maxn];
int n,k;
int main(){
	cin>>n>>k;
	ll ans = 0;
	for(int i= 0;i < n;++i) scanf("%I64d%I64d",&e[i].t,&e[i].b);
	sort(e,e+n);
	for(int i = 0;i < k;++i) {
		q.push(e[i].t);
		sum+=e[i].t;
		ans =max(ans, sum*e[i].b);
	}
	
	for(int i = k;i < n;++i){
		q.push(e[i].t);
		sum+=e[i].t;
		sum-=q.top();
		q.pop();
		ans = max(ans,sum*e[i].b);
	}
	cout<<ans<<endl;
}