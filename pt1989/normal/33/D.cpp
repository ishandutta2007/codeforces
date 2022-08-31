//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>



//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>




#define oo 				0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd
using namespace std;

const int mxn = 1024;
ll x[mxn], y[mxn];
ll cx[mxn], cy[mxn], r[mxn];

vector<int> children[mxn];
vector<int> circhild[mxn];
const ll SUPERMAX = 9223372036854775805LL;

ll hyp(ll x, ll y) {
	return x*x + y*y;
}
int dist[1024][1024];

vector< pair<int, int> > solve(int v) {
	vector< pair<int, int> > ret;
	for (int i=0; i < children[v].size(); i++) {
		int ci = children[v][i];
		ret.pb( make_pair( ci, 0 ) );
	}
	
	for (int i=0; i < circhild[v].size(); i++) {
		vector< pair<int, int> > z = solve( circhild[v][i] );
		int lim = ret.size();
		for (int j=0; j < z.size(); j++) {
			pair<int,int> q = z[j];
			q.second ++;
			ret.pb(q);
			for (int k=0; k < lim; k++) {
				pair<int,int> w = ret[k];
				//cout << "making edge from " << q.first << " to " << w.first << " with value " << (q.second + w.second) << endl;
				dist[w.first][q.first] = dist[q.first][w.first] = q.second + w.second;
			} 
		} 
	}
	
	/* 
	cout <<"Circle " << v << endl;
	
	for (int i=0; i < ret.size(); i++)
	cout << "goes to point with distance " << ret[i].first << " " << ret[i].second << endl;
	cout<<endl;
	
	for (int i=0; i < children[v].size(); i++)
	cout << children[v][i] << endl; cout <<endl;
	// */
	return ret;
}

int main(){
	
	int n, m, k;
	s(n); s(m); s(k);
	
	for (int i=0; i < n; i++) {
		sl(x[i]); sl(y[i]);
	}
	
	for (int i=0; i < m; i++) {
		sl(r[i]); sl(cx[i]); sl(cy[i]); 
	}
	// add very large super-circle
	cx[m] = 0;
	cy[m] = 0;
	r[m] = (ll)2e9;
	m++;
	//for each point find smallest circle that contains it ( else will find super-circle )
	for (int p=0; p < n; p++) {
		ll bval = SUPERMAX;
		int sol = -1;
		for (int i=0; i < m; i++) {
			ll cdist = hyp( cx[i] - x[p], cy[i] - y[p] );
			
			if (cdist <= r[i]*r[i]) {
				if (sol==-1 || r[i] < bval) {
					bval = r[i];
					sol = i;
				}
			}
		}
		children[sol].pb(p);
	}
	
	//find for each circle, the smallest circle that contains it ( or finds super circle )
	for (int i=0; i < m; i++) {
		int op = i;
		ll bval = SUPERMAX;
		for (int j=0; j < m; j++)
		if ( j != i && r[j] >= r[i] ) {
			ll cdist = hyp( cx[i] - cx[j], cy[i] - cy[j] );
			
			if ( cdist <= r[j]*r[j] ) {
				if ( r[j] < bval ) {
					op = j;
					bval = r[j];
				}
			}
		}
		if (op==i) continue;
		
		circhild[op].pb(i);
	}
	solve(m-1);
	
	for (int i=0; i < k; i++) {
		int f, t;
		s(f); s(t);
		printf("%d\n", dist[f-1][t-1] );
	}
	
	
	
	return 0;
}