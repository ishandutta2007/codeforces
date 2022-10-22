#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

int st[1<<18][8], sz = 1<<17;

void update(int p, int v){
	p+=sz;
	for (int i=0; i<6; i++){
		if (i != v) st[p][i] = 1;
		else st[p][i] = 0;
	}
	for (p>>=1; p; p>>=1){
		int l = p<<1, r = p<<1|1;
		st[p][0] = st[l][0] + st[r][0];
		st[p][1] = st[l][1] + st[r][1];
		st[p][2] = st[l][2] + st[r][2];
		st[p][3] = max(st[l][3] + st[r][1], st[l][0] + st[r][3]);
		st[p][4] = max(st[l][4] + st[r][2], st[l][1] + st[r][4]);
		st[p][5] = max(st[l][3] + st[r][4], max(st[l][0]+st[r][5], st[l][5] + st[r][2]));
	}
}

int rquery(int l, int r){
	int lans[6], rans[6];
	for (int i=0; i<6; i++) lans[i] = rans[i] = 0;
	for (l+=sz, r+=sz; l<r; l>>=1, r>>=1){
		if (l&1){
			int ans1[6];
			for (int i=0; i<6; i++) ans1[i] = lans[i];
			lans[0] = ans1[0] + st[l][0];
			lans[1] = ans1[1] + st[l][1];
			lans[2] = ans1[2] + st[l][2];
			lans[3] = max(ans1[3] + st[l][1], ans1[0] + st[l][3]);
			lans[4] = max(ans1[4] + st[l][2], ans1[1] + st[l][4]);
			lans[5] = max(ans1[3] + st[l][4], max(ans1[0]+st[l][5], ans1[5] + st[l][2]));
			l++;
		}
		if (r&1){
			r--;
			int ans1[6];
			for (int i=0; i<6; i++) ans1[i] = rans[i];
			rans[0] = st[r][0] + ans1[0];
			rans[1] = st[r][1] + ans1[1];
			rans[2] = st[r][2] + ans1[2];
			rans[3] = max(st[r][3] + ans1[1], st[r][0] + ans1[3]);
			rans[4] = max(st[r][4] + ans1[2], st[r][1] + ans1[4]);
			rans[5] = max(st[r][3] + ans1[4], max(st[r][0]+ans1[5], st[r][5] + ans1[2]));
		}
	}
	return max(lans[3] + rans[4], max(lans[0]+rans[5], lans[5] + rans[2]));;
}

int query(int l, int r){
	return rquery(l,r+1);
}

ll n, m,q, k, t, a, b, c;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	cin >> s;
	for (int i=0; i<n; i++){
		update(i,s[i]-'a');
	}
	while (q--){
		char x;
		cin >> a >> x;
		update(a-1, x-'a');
		cout << n-query(0,n-1) << "\n";
	}
}