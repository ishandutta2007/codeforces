#include"bits/stdc++.h"
using namespace std;

long double sy;
long double a;
long double b;
int n;
vector<pair<int, int> > v;
int q;
vector<pair<double, double> > vv;
vector<double> sum;


int main(){
	cin >> sy >> a >> b;
	cin >> n;
	for (int i = 0; i < n; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		v.push_back(make_pair(l, r));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		if (vv.size() == 0){
			vv.push_back(v[i]);
			continue;
		}
		if (vv.back().second >= v[i].first){
			vv.back().second = max(vv.back().second, (double)v[i].second);
			continue;
		}
		vv.push_back(v[i]);
	}
	sum.assign(vv.size(), 0);
	for (int i = 0; i < vv.size(); i++){
		if (i){
			sum[i] += sum[i - 1];
		}
		sum[i] += vv[i].second - vv[i].first;
	}
	cin >> q;
	while (q--){
		int x, y;
		scanf("%d%d", &x, &y);
		double lef;
		double rig;
		double xx = x;
		double yy = y;
		lef = (a - xx) / (sy - yy)*(0 - yy)+xx;
		rig = (b - xx) / (sy - yy)*(0 - yy)+xx;
		int L = upper_bound(vv.begin(), vv.end(), make_pair(lef, (double)(INT_MAX) ) )-vv.begin();
		L--;
		int R = upper_bound(vv.begin(), vv.end(), make_pair(rig, (double)(INT_MAX))) - vv.begin();
		while (L <= R){
			if (L < 0 || L >= vv.size()){
				L++;
				continue;
			}
			if (vv[L].first >= rig){
				L++;
				continue;
			}
			if (vv[L].second <= lef){
				L++;
				continue;
			}
			break;
		}
		while (L <= R){
			if (R < 0 || R >= vv.size()){
				R--;
				continue;
			}
			if (vv[R].first >= rig){
				R--;
				continue;
			}
			if (vv[R].second <= lef){
				R--;
				continue;
			}
			break;
		}
		double ans = 0;
		if (L <= R){
			double g1 = max(vv[L].first, lef);
			double g2 = min(vv[L].second, rig);
			ans += g2 - g1;
			L++;
		}
		if (L <= R){
			double g1 = max(vv[R].first, lef);
			double g2 = min(vv[R].second, rig);
			ans += g2 - g1;
			R--;
		}
		if (L <= R){
			ans += sum[R];
			if (L)ans -= sum[L - 1];
		}
		ans *= (sy - yy) / (0 - yy);
		printf("%.16f\n", ans);
	}
	return 0;
}