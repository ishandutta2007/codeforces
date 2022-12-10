#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 85 - 69, maxsq = 315;
int a[maxn], dadash[maxn], cnt[maxn];
int n, que;

void fix(int id){
	for(int i = (id + 1) * maxsq - 1; i >= id * maxsq; i--){
		int newpos = i + a[i];
		if(newpos >= n){
			dadash[i] = i;
			cnt[i] = 0;
		}
		else if(i / maxsq == newpos / maxsq){
			dadash[i] = dadash[newpos];
			cnt[i] = cnt[newpos] + 1;
		}
		else{
			dadash[i] = newpos;
			cnt[i] = 1;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> que;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = maxn / 2 / maxsq; i >= 0; i--)
		fix(i);
	while(que--){
		int ty;
		cin >> ty;
		if(ty){
			int fi, count = 1;
			cin >> fi;
			fi--;
			while(dadash[fi] != fi)
				count += cnt[fi], fi = dadash[fi];
			count += cnt[fi];
			cout << fi + 1 << ' ' << count << '\n';
		}
		else{
			int fi, se;
			cin >> fi >> se;
			fi--;
			a[fi] = se;
			fix(fi / maxsq);
		}
	}
	return 0;
}