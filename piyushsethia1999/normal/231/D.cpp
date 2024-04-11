#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int x1, x2, x3, x, y, z, a1, a2, a3, a4, a5, a6;
	cin >> x >> y >> z >> x1 >> x2 >> x3 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	int sum = 0;
	if (x > x1) {
		sum += a6;
	}
	else if(x < 0) {
		sum += a5;
	}
	if (y > x2) {
		sum += a2;
	}
	else if(y < 0) {
		sum += a1;
	}
	if (z > x3) {
		sum += a4;
	}
	else if(z < 0){
		sum += a3;
	}
	cout<<sum;
}