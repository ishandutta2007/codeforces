#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , m , k;
int x[N] , y[N];
bool rekt(vector < pair < int , int > > &v , int mx){
	int sum = 0;
	sort(v.begin() , v.end());
	if(v.empty() || v[0].first > 1){
		return 0;
	}
	for(auto it : v){
		if(it.first > mx){
			break;
		}
		if(it.second == 1){
			++sum;
		}
		else{
			--sum;
		}
		if(sum == 0){
			return 0;
		}
	}
	return 1;
}
void checkx(int idx , int &ql , int &qr , int tim){
	if(idx < 1 || idx > n){
		return;
	}
	vector < pair < int , int > > v;
	v.clear();
	for(int i = 1 ; i <= k ; ++i){
		if(abs(idx - x[i]) <= tim){
			v.emplace_back(max(1 , y[i] - tim) , 1);
			v.emplace_back(min(m , y[i] + tim) + 1 , 2);
		}
	}
	if(!rekt(v , m)){
		ql = min(ql , idx);
		qr = max(qr , idx);
	}
}
void checky(int idx , int &ql , int &qr , int tim){
	if(idx < 1 || idx > m){
		return;
	}
	vector < pair < int , int > > v;
	v.clear();
	for(int i = 1 ; i <= k ; ++i){
		if(abs(idx - y[i]) <= tim){
			v.emplace_back(max(1 , x[i] - tim) , 1);
			v.emplace_back(min(n , x[i] + tim) + 1 , 2);
		}
	}
	if(!rekt(v , n)){
		ql = min(ql , idx);
		qr = max(qr , idx);
	}
}
bool check(int tim){
	int minx , miny , maxx , maxy;
	minx = n + 1;
	miny = m + 1;
	maxx = 0;
	maxy = 0;
	checkx(1 , minx , maxx , tim);
	checkx(n , minx , maxx , tim);
	for(int i = 1 ; i <= k ; ++i){
		int l = x[i] - tim;
		int r = x[i] + tim;
		checkx(l - 1 , minx , maxx , tim);
		checkx(l , minx , maxx , tim);
		checkx(r , minx , maxx , tim);
		checkx(r + 1 , minx , maxx , tim);
	}
	checky(1 , miny , maxy , tim);
	checky(m , miny , maxy , tim);
	for(int i = 1 ; i <= k ; ++i){
		int l = y[i] - tim;
		int r = y[i] + tim;
		checky(l - 1 , miny , maxy , tim);
		checky(l , miny , maxy , tim);
		checky(r , miny , maxy , tim);
		checky(r + 1 , miny , maxy , tim);
	}
	if(maxx - minx <= 2 * tim && maxy - miny <= 2 * tim){
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d %d" , x + i , y + i);
	}
	int l = 0;
	int r = 1e9;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n" , l);
}