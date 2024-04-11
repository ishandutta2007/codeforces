#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

const int N = 234567, BASE = 950, VAL = 12345678;

int n, m, q;
llint sum[N], a[N], b[N];


struct ii{
  	int first;
  	int second;
  	int id;
  	int ginz;
  	//ii (int a, int b, int c) first : a, second : b, id : c;
}query[N], team[BASE][BASE];

int nTeam[BASE];
llint cnt[VAL], ans, result[N];

bool cmp(ii u, ii v){
	return u.second < v.second;
}

bool cmp1(ii u, ii v){
	if(u.ginz == v.ginz) return u.second < v.second;
	return u.ginz < v.ginz;	
}

void update(llint val, int add){
	llint app = (cnt[val] * cnt[val] * val);
	llint sub = ((cnt[val] + add) * (cnt[val] + add) * val);
	app -= sub;
//	cout << val << " " << cnt[val] << " " << ans << " " << app << endl;

	ans -= app;
	cnt[val] += add;		
}

void write(){
	printf("%d %d\n", n, q);
	for(int i = 1; i <= n; ++i){
		printf("%lld ", a[i]);
	}
	puts("");
	for(int i = 1; i <= q; ++i){
		printf("%d %d\n", query[i].first, query[i].second);
	}
	exit(0);
}
//
void big(){
//	exit(0);	
	int base = sqrt(n);        int maxbase = 0;
       	for(int i = 1; i <= q; ++i){
	//        cout << query[i].first << " " << query[i].second << endl;
		int belong = (query[i].first - 1) / base + 1;
		query[i].ginz = belong;	//	cout << belong << " " << base << endl;
	}

//	cout << nTeam[1] << endl;
	
	 sort(query + 1, query + q + 1, cmp1);
		ans = 0;

	//	cout << team[i][1].id << endl;
		
	//	cout << "YES" << endl;

		for(int j = query[1].first; j <= query[1].second; ++j){
	//	        if(i == 3) cout << a[j] << " " << team[i][1].first << " " << team[i][1].second << endl;
		        int add = 1; int val = a[j];
		        llint app = (cnt[val] * cnt[val] * val);
			llint sub = ((cnt[val] + add) * (cnt[val] + add) * val);
			app -= sub;
//	cout << val << " " << cnt[val] << " " << ans << " " << app << endl;

			ans -= app;
			cnt[val] += add;
		//	update(a[j], 1);
		}       

		result[query[1].id] = ans;

		for(int j = 2; j <= q; ++j){
		//	if(i == 2) cout << team[i][j].first << " " << team[i][j].second << endl;
		       
			int lef = query[j - 1].first, rig = query[j - 1].second;

			//if(team[i][j].first == 13 && team[i][j].second == 15){
		//		cout << lef << " " << rig << " " << ans << endl;
		//	}

			if(lef < query[j].first) for(int k = lef; k < query[j].first; ++k){
				int val = a[k];                             
			//	app -= sub;
//	cout << val << " " << cnt[val] << " " << ans << " " << app << endl;

				ans -= (cnt[val] * 2 - 1) * llint(val);
				--cnt[val];
			//	update(a[k], -1);
			}
			if(query[j].first < lef) for(int k = query[j].first; k < lef; ++k){
			//	if(team[i][j].id == 3) cerr << "YES";
				int add = 1;     int val = a[k];
				

//	cout << val << " " << cnt[val] << " " << ans << " " << app << endl;

				ans += (cnt[val] * 2 + 1) * llint(val);
				cnt[val]++;
			//	update(a[k], 1);
			}
			if(query[j].second < rig) for(int k = query[j].second + 1; k <= rig; ++k){
				int val = a[k];                             
			//	app -= sub;
//	cout << val << " " << cnt[val] << " " << ans << " " << app << endl;

				ans -= (cnt[val] * 2 - 1) * llint(val);
				--cnt[val];			//	update(a[k], -1);
			}
			if(rig < query[j].second) for(int k = rig + 1; k <= query[j].second; ++k){
			        int add = 1;     int val = a[k];
				

//	cout << val << " " << cnt[val] << " " << ans << " " << app << endl;

				ans += (cnt[val] * 2 + 1) * llint(val);
				cnt[val]++;		//		update(a[k], 1);
			}
	/*		if(team[i][j].id == 3){
				cout << "YES";
			}             */
			result[query[j].id] = ans; 
		}

	for(int i = 1; i <= q; ++i){
	//	cout << result[i] << " " << sum[i] << endl;
	/*	if(result[i] != sum[i]){
			puts("Wrong Answer at:");
			cout << query[i].first << " " << query[i].second << " " << sum[i] << " " << result[i] << endl << endl;
			write();
		}*/
		printf("%lld\n", result[i]);
	}
//	puts("Correct");
}


//Day la code moi

void fakeinput(){
	srand(time(NULL));
 	for(int i = 1; i <= n; ++i){
		a[i] = rand() % 100 + 1;
	}

	for(int i = 1; i <= q; ++i){
		int lef, rig;
	//	scanf("%d%d", &lef, &rig);
       	        lef = rand() % n + 1;
       	        rig = lef + rand() % (n - lef + 1);
       	    	query[i] = {lef, rig, i};
	}
}

void realinput(){
	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
	}
	for(int i = 1; i <= q; ++i){
		int lef, rig;
		scanf("%d%d", &lef, &rig);
		query[i] = {lef, rig, i};
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("array.inp", "r", stdin);
		freopen("array.out", "w", stdout);	
	#endif
	 
	//srand(time(NULL));

	scanf("%d%d", &n, &q);
	realinput();
	//fakeinput();
		//	exit(0);
//	small();
	big();
}