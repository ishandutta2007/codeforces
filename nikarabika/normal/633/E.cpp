//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1000 * 1000 + 85 - 69;
int v[maxn],
	c[maxn],
	vst[maxn],
	cst[maxn],
	vstsz, cstsz,
	n, k;
LD ans[maxn],
   Ans;

bool cmp(int i, int j){
	return i > j;
}

int getv(int idx){
	return v[*lower_bound(vst, vst + vstsz, idx, cmp)];
}

int getc(int idx){
	return c[*lower_bound(cst, cst + cstsz, idx, cmp)];
}

void find_ans(int idx){
	int lo = idx, hi = n - 1;
	if(getv(lo) >= getc(lo)){
		ans[idx] = LD(getc(lo));
		return;
	}
	if(getv(hi) < getc(hi)){
		ans[idx] = LD(getv(hi));
		return;
	}
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(getv(mid) < getc(mid))
			lo = mid;
		else
			hi = mid;
	}
	ans[idx] = LD(1) * max(getv(lo), getc(hi));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> v[i], v[i] *= 100;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = n - 1; i >= 0; i--){
		while(cstsz and c[cst[cstsz - 1]] >= c[i])
			cstsz--;
		cst[cstsz++] = i;
		while(vstsz and v[vst[vstsz - 1]] <= v[i])
			vstsz--;
		vst[vstsz++] = i;
		find_ans(i);
	}
	sort(ans, ans + n);
	LD C = LD(1) / LD(n);
	//cout << C << endl;
	for(int i = 0; i <= n - k; i++){
		Ans += C * ans[i];
		//if(isnan(Ans)) cout << C << ' ' << ans[i] << ' ' << makh << endl;
		C = C * LD(n - i - k) / LD(n - i - 1);
	}
	cout.precision(15);
	cout << fixed << Ans * k << endl;
	return 0;
}