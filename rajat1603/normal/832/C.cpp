#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-12;
int n , s;
int x[N] , v[N] , dir[N];
const int M = 1000000;
inline double get(int i , int p){
	if(dir[i] == 1){
		double t = x[i];
		t /= v[i];
		if(p - t * s >= 0){
			return t;
		}
		t = x[i] - p;
		t /= v[i] - s;
		return t + (1.0 * x[i] - v[i] * t) / (0.0 + s + v[i]);
	}
	if(dir[i] == 2){
		double t = M - x[i];
		t /= v[i];
		if(p + t * s <= M){
			return t;
		}
		t = p - x[i];
		t /= v[i] - s;
		return t + (1.0 * M - (x[i] + v[i] * t)) / (0.0 + s + v[i]);
	}
}
bool intersect(pair < int , int > a , pair < int , int > b){
	return min(a.second , b.second) - max(a.first , b.first) + 1 > 0;
}
int sum[M + 6];
inline bool check(double t){
	vector < pair < int , int > > v1;
	vector < pair < int , int > > v2;
	v1.clear();
	v2.clear();
	for(int i = 1 ; i <= n ; ++i){
		int ql = 0;
		int qr = M;
		if(dir[i] == 1){
			if(x[i] - v[i] * t <= 0){
				v1.push_back(make_pair(ql , qr));
				continue;
			}
			if(x[i] - (v[i] + s) * t > eps){
				continue;
			}
			int l = x[i];
			int r = M;
			ql = max(ql , x[i]);
			while(l < r){
				int mid = l + r + 1 >> 1;
				if(get(i , mid) <= t + eps){
					l = mid;
				}
				else{
					r = mid - 1;
				}
			}
			qr = min(qr , r);
			v1.push_back(make_pair(ql , qr));
		}
		else{
			if(x[i] + v[i] * t >= M){
				v2.push_back(make_pair(ql , qr));
				continue;
			}
			if(x[i] + (v[i] + s) * t < M - eps){
				continue;
			}
			int l = 0;
			int r = x[i];
			qr = min(qr , x[i]);
			while(l < r){
				int mid = l + r >> 1;
				if(get(i , mid) <= t + eps){
					r = mid;
				}
				else{
					l = mid + 1;
				}
			}
			ql = max(ql , l);
			v2.push_back(make_pair(ql , qr));
		}
	}
	memset(sum , 0 , sizeof(sum));
	for(auto it : v2){
		++sum[it.first];
		--sum[it.second + 1];
	}
	for(int i = 1 ; i <= M ; ++i){
		sum[i] += sum[i - 1];
	}
	for(int i = 0 ; i <= M ; ++i){
		sum[i] = !!sum[i];
	}
	for(int i = 1 ; i <= M ; ++i){
		sum[i] += sum[i - 1];
	}
	for(auto it : v1){
		if(sum[it.second] - (it.first ? sum[it.first - 1] : 0)){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d %d" , &n , &s);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , x + i , v + i , dir + i);
	}
	double l = 0;
	double r = 1e6 + 6;
	for(int i = 0 ; i < 70 ; ++i){
		double mid = (l + r) / 2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	printf("%.9lf\n" , r);
}