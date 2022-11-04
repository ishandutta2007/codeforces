#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXVAL = (int) 1e7;
pair<int, int> sol[MAXVAL + 1];
int low[MAXVAL + 1];


int main() {
#ifdef HOME
    //ifstream cin("B.in");
    //ofstream cout("B.out");
#endif
   	int	i, j, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    // gcd(d1, d2) = 1

    //cin >> n;
    scanf("%d" ,&n);
    vector<int> arr(n);
    for(i = 0; i < n; i++) {
    	//cin >> arr[i];
    	scanf("%d" ,&arr[i]);
    }

    for(i = 2; i <= MAXVAL; i++) {
    	if(low[i] == 0) {
	    	for(j = i; j <= MAXVAL; j += i) {
	    		low[j] = i;
	    	}
    	}
    }

    for(i = 0; i < n; i++) {
    	int val = arr[i];
    	if(sol[val].first != 0) {
			continue;    		
    	}
    	sol[val] = {-1, -1};
    	
    	vector<int> pws;
    	while(val != 1) {
    		int cur = low[val];
    		pws.push_back(1);
    		while(low[val] == cur) {
    			pws.back() *= cur;
    			val /= cur;
    		}
    	}

    	int sz = (int)pws.size();
    	for(int conf = 1; conf < (1 << (sz - 1)); conf++) {
    		int d = 1;
    		for(j = 0; j < sz; j++) {
    			if(conf & (1 << j)) {
    				d *= pws[j];
    			}
    		}
    		//cerr << arr[i] << " " << d << " " << arr[i] / d << "\n";
    		if(__gcd(d + arr[i] / d, arr[i]) == 1) {
    			sol[arr[i]] = {d, arr[i] / d};
    			break;
    		}
    	}
    }

    for(i = 0; i < n; i++) {
    	//cout << sol[arr[i]].first << " ";
    	printf("%d " ,sol[arr[i]].first);
    }
    //cout << "\n";
    printf("\n");
    for(i = 0; i < n; i++) {
    	//cout << sol[arr[i]].second << " ";
    	printf("%d " ,sol[arr[i]].second);
    }

    return 0;
}