#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

ll a, b;

ll calc(ll num) {
 	int l = 0;
 	ll ret = 0;
 	ll tmp = num;
 	while (tmp) {
 	 	//cerr << "tmp: " << tmp << endl;
 	 	ret += l - 1;
 	 	++l;
 	 	tmp /= 2; 	 	
 	}

 	//cerr << l << endl;
 	//cerr << ret << endl;

 	int lastzero = 0;
 	int numzero = 0;
 	for (int i = 0; i < l; ++i) {
 	 	if (!(num & (1ll << i))) {
 	 	 	lastzero = i;
 	 	 	++numzero;
 	 	}
 	}
 	//cerr << lastzero << " " << numzero << endl;
 	if (numzero <= 1) {
		ret += l - lastzero;
	} else {
	 	ret += l - lastzero - 1;
	}
	return ret;
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%I64d%I64d", &a, &b);

    //cerr << calc(b);

    cout << calc(b) - calc(a - 1) << "\n";

    return 0;
}