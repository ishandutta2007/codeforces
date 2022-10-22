#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;


int main()
{
	ll k, z, n, m, a, b, c;
	int c1, c2, c3, c4, c5, c6, c7;
	std::vector<ll> v;
	std::map<ll, ll> N;
	std::map<ll, ll> N2;
	std::map<ll, ll> A;
	std::map<ll, ll> B;
	std::cin >> n;

	for (c1 = 0; c1 < n; c1++){

		std::cin >> a;
		v.push_back(a);

		if (N.find(a) == N.end()){

			N[a] = 0;
			A[a] = c1;


		}
		else{

			N[a]++;

		}


	}
	ll M = 0;
	for (c1 = n - 1; c1 >= 0; c1--){

		a = v[c1];
		if (a > M){ M = a; }
		if (N2.find(a) == N2.end()){

			N2[a] = 5;
			B[a] = c1;


		}





	}
	ll ma = 0;
	for (c1 = 1; c1 < M + 1; c1++){

		if (N.find(c1) != N.end()){
			if (N[c1] > ma){ ma = N[c1]; }
		}

	}
	ll mi = 87658556ll;
	ll ans1;
	ll ans2;
	for (c1 = 1; c1 < M+1; c1++){

		if (N.find(c1) != N.end()){
            //cout << c1 <<" " << N[c1] << " " << A[c1] << " " << B[c1] << "\n";
			if (N[c1] == ma && B[c1] - A[c1] < mi){ mi = B[c1] - A[c1]; ans1 = A[c1] + 1; ans2 = B[c1] + 1; }
		}

	}

	std::cout << ans1 << " " << ans2 << "\n";


	return 0;
}