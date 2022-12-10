#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;
typedef set<int>::iterator init;
typedef set<pie>::iterator pit;

#define MP make_pair
#define L first
#define R second

set<int> cuth, cutv;
set<pie> dh, dv;
int w, h, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> w >> h >> n;
	
	cuth.insert(0);
	cuth.insert(h);
	dh.insert(MP(h, 1));
	
	cutv.insert(0);
	cutv.insert(w);
	dv.insert(MP(w, 1));

	while(n--){
		char fi;
		int se;
		cin >> fi >> se;
		if(fi == 'H'){
			init it1 = cuth.lower_bound(se), it2 = it1;
			it1--;
			int dis1 = se - (*it1),
				dis2 = (*it2) - se;
			pit it3 = dh.lower_bound(MP((*it2) - (*it1), 0));
			dh.erase(it3);
			pie t = *it3;
			t.R--;
			if(t.R)
				dh.insert(t);

			it3 = dh.lower_bound(MP(dis1, 0));
			if(it3 == dh.end() or it3->L != dis1)
				dh.insert(MP(dis1, 1));
			else{
				t = *it3;
				dh.erase(it3);
				t.R++;
				dh.insert(t);
			}
			it3 = dh.lower_bound(MP(dis2, 0));
			if(it3 == dh.end() or it3->L != dis2)
				dh.insert(MP(dis2, 1));
			else{
				t = *it3;
				dh.erase(it3);
				t.R++;
				dh.insert(t);
			}
			cuth.insert(se);
		}		
		else{
			init it1 = cutv.lower_bound(se), it2 = it1;
			it1--;
			int dis1 = se - (*it1),
				dis2 = (*it2) - se;
			pit it3 = dv.lower_bound(MP((*it2) - (*it1), 0));
			dv.erase(it3);
			pie t = *it3;
			t.R--;
			if(t.R) dv.insert(t);

			it3 = dv.lower_bound(MP(dis1, 0));
			if(it3 == dv.end() or it3->L != dis1)
				dv.insert(MP(dis1, 1));
			else{
				t = *it3;
				dv.erase(it3);
				t.R++;
				dv.insert(t);
			}
			it3 = dv.lower_bound(MP(dis2, 0));
			if(it3 == dv.end() or it3->L != dis2)
				dv.insert(MP(dis2, 1));
			else{
				t = *it3;
				dv.erase(it3);
				t.R++;
				dv.insert(t);
			}
			cutv.insert(se);
		}
		pit ith = dh.end(), itv = dv.end();
		ith--;
		itv--;
		cout << 1LL * (ith->L) * (itv->L) << endl;
	}

	return 0;
}