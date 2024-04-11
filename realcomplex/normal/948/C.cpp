#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = (int)1e5 + 9;
ll pref[N];
ll siz[N];
ll temp[N];
ll dmg[N];
ll extra[N];

void init(){
	for(int i = 1;i<N;i++)
		pref[i] = (ll)1e15;
}

int main(){
	fastIO;
	int n;
	cin >> n;
	init();
	for(int i = 1;i<=n;i++){
		cin >> siz[i];
	}
	for(int i = 1;i<=n;i++){
		cin >> temp[i];
		pref[i] = temp[i]+pref[i-1];
	}
	int xj;
	for(int i = 1;i<=n;i++){
		if(siz[i] <= temp[i]){
			extra[i]+=siz[i];
			continue;
		}
		siz[i] += pref[i-1];
		xj = lower_bound(pref,pref+N,siz[i])-pref;
		//cout << xj << " ";
		dmg[i]++;
		dmg[xj]--;
		siz[i] -= pref[i-1];
		siz[i] -= pref[xj-1]-pref[i-1];
		extra[xj] += siz[i];
	}
	for(int i = 1;i<=n;i++){
		dmg[i] += dmg[i-1];
		cout << dmg[i] * temp[i] + extra[i] << " ";
	}
	return 0;
}