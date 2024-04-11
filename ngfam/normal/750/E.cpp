#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, f[5];
string s;

struct node{
	int a[5][5];

		
	
};



node combine(node t, node other){
		node result;
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				result.a[i][j] = n + 1;
				for(int k = 0; k < 5; ++k){
					result.a[i][j] = min(result.a[i][j], t.a[i][k] + other.a[k][j]);
				}
			}
		}
		return result;
	}

node init(){
        node result;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			result.a[i][j] = n + 1;
		}
		result.a[i][i] = 0;
	}	
	return result;
}


node it[N * 5], riki[N];

void build(int i, int l, int r){
	if(l == r){
		it[i] = riki[l];
		return;
	}

	int mid = (l + r) >> 1;

	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);

	it[i] = combine(it[i * 2] ,it[i * 2 + 1]);
}

int d, c;


node query(int i, int l, int r){
	 if(l >= d && r <= c){
	//        cout << l << " " << r << endl;
	//	write(it[i]);
		
		return it[i];
	 }
	 int mid = (l + r) >> 1;
	 
	 if(c <= mid) return query(i * 2, l, mid);
	 if(d > mid) return query(i * 2 + 1, mid + 1, r);

	 return combine(query(i * 2, l, mid), query(i * 2 + 1, mid + 1, r));
}

node ask(int l, int r){
	d = l; c = r;
	return query(1, 1, n);
}

int path(node u){
	int done[5], f[5];
	
	for(int i = 0; i < 5; ++i){
		done[i] = 0;
		f[i] = n + 1;
	}                            	

	f[0] = 0;
	
	while(true){
		int node = 5;
		for(int i = 0; i < 5; ++i){
			if(f[i] != n + 1 && !done[i]){
				if(node == 5) node = i;
				else{
					if(f[node] > f[i]) node = i;
				}
			}
		}

		if(node == 5) break;
		done[node] = 1;

		for(int i = 0; i < 5; ++i){
			f[i] = min(f[i], f[node] + u.a[node][i]);
		}
	}

	for(int i = 0; i < 5; ++i){
		cout << f[i] << endl;
	}

	return f[4];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> s;

	for(int i = 0; i < s.size(); ++i){
		riki[i + 1] = init();

		if(s[i] == '2'){
			riki[i + 1].a[0][0] = 1;
			riki[i + 1].a[0][1] = 0;
		}
		if(s[i] == '0'){
			riki[i + 1].a[1][1] = 1;
			riki[i + 1].a[1][2] = 0;
		}
		if(s[i] == '1'){
			riki[i + 1].a[2][2] = 1;
			riki[i + 1].a[2][3] = 0;
		}
		if(s[i] == '6'){
			riki[i + 1].a[3][3] = 1;
			riki[i + 1].a[4][4] = 1;
		}
		if(s[i] == '7'){
			riki[i + 1].a[4][4] = 0;
			riki[i + 1].a[3][4] = 0;
		}
		
		

	}

	build(1, 1, n);


		/*for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				cout << curr.a[i][j] << " ";
			}
			cout << endl;
		}
		
		       */

     /*  for(int i = 51; i <= 63; ++i){
       		cout << s[i - 1];
       }*/

       //cout << endl;
	for(int i = 1; i <= m; ++i){
		int lef, rig;
		cin >> lef >> rig;

		node curr = ask(lef, rig);

		int ans = curr.a[0][4];

	/*	for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				cout << curr.a[i][j] << " ";
			}
			cout << endl;
		}*/
		
			        
		if(ans == n + 1) ans = -1;
		cout << ans << '\n';     
	}

	return 0;
}