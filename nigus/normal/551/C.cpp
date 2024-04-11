#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;

std::vector<ll> a;
ll n,m;
ll nu,du;
ll sum;
int test(ll t){

	nu = 0;
	ll fail = 0;
	ll ner = 0;
	ll tid;
	ll S=0;
	int ans = 0;
	for (du = 0; du < m; du++){
		tid = nu + 1;
		while (tid < t){

		if (nu < n){
			if (a[nu] - ner > t - tid){ ner += t - tid; S += t - tid; break; }
			else{ tid += a[nu] - ner; S += a[nu] - ner; nu++; ner = 0;}
			}

		tid++;
		
		if (nu >= n || S >= sum){ ans = 1; fail=1; break; }

		//cout << du << " " << nu << " " << S << "\n";

	}

		
		if (fail == 1){ break; }
	}

	return ans;
}



int main()
{
	ll k,x,y,b,z;
	int c1, c2, c3, c4, c5, c6;
	sum = 0;
	std::cin >> n >> m;
	for (c1 = 0; c1 < n; c1++){

		std::cin >> b;
		sum += b;
		a.push_back(b);
	}

	x = 0ll;
	y = 200000000000000ll;

	int T;
	//T = test(5);

	
	
	for (c1 = 0; c1 < 300; c1++){

		z = ceil((x + y) / 2);
		T = test(z);

		if (T == 0){ x = z;}
		else{ y = z; }

	}
	if (sum== 0){ y = 0; }
	std::cout << y << "\n";

	
	
	return 0;
}