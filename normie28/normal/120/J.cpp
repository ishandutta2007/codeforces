#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first 
#define S second
const ll N = 1e5+12;
int n, a[N], b[N];
pair<pair<int,int>, int> p[N];
set<pair<pair<int,int>, int> > s;
set<pair<pair<int,int>, int> > :: iterator it1, it2;
ll ans = 1e17, ans1, ans2;
ll dis(pair<pair<int,int>, int> x, pair<pair<int,int>, int> y){
	ll dx = x.F.S - y.F.F;
	ll dy = x.F.F - y.F.S;
	return (dx * dx) + (dy * dy);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i]>>b[i];
		p[i].F.F = fabs(a[i]);
		p[i].F.S = fabs(b[i]);
		p[i].S = i; 
	}
	sort(p+1, p+n+1);
	int j = 1;
	for(int i = 1 ; i <= n ; i ++){
		int now = ceil(sqrt(ans));
		while(p[i].F.F - p[j].F.F >= ans){
			s.erase({{p[j].F.S, p[j].F.F}, p[j].S});
			j ++;
		}
		it1 = s.lower_bound({{p[i].F.S-now, p[i].F.F}, -1e7});
		it2 = s.lower_bound({{p[i].F.S+now, p[i].F.F}, -1e7});
		for(;it1 != it2; it1 ++){
			if(dis((*it1),p[i]) < ans){
				ans = dis((*it1),p[i]);
				ans1 = it1->S;
				ans2 = p[i].S;	
			}
		}
		s.insert({{p[i].F.S, p[i].F.F}, p[i].S});		
	}
	int k1 = 1 + (a[ans1] < 0) * 1 + (b[ans1] < 0) * 2;
	int k2 = 1 + (a[ans2] > 0) * 1 + (b[ans2] > 0) * 2;
	cout<<ans1<<' '<<k1<<' '<<ans2<<' '<<k2;
}