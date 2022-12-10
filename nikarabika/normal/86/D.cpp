//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 2e5 + 85 - 69;
const int maxsq = 500;
int ql[maxn],
	qr[maxn],
	ord[maxn],
	n, q;
int cnt[maxn * 5],
   a[maxn];
LL ans[maxn],
   cur_ans;

bool cmp(int i, int j){
	return qr[i] / maxsq == qr[j] / maxsq ? ql[i] > ql[j] : qr[i] < qr[j];
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%I64d", a + i);
	for(int i = 0; i < q; i++)
		scanf("%d%d", ql+i, qr+i), ql[i]--, qr[i]--;
	for(int i = 0; i < q; i++)
		ord[i] = i;
	sort(ord, ord + q, cmp);
	int st = 0,
		en = -1;
	for(int i = 0; i < q; i++){
		int id = ord[i];
		while(st > ql[id]){
			--st;
			int val = a[st];
			cur_ans -= 1LL * cnt[val] * cnt[val] * val;
			cnt[val]++;
			cur_ans += 1LL * cnt[val] * cnt[val] * val;
		}
		while(en < qr[id]){
			++en;
			int val = a[en];
			cur_ans -= 1LL * cnt[val] * cnt[val] * val;
			cnt[val]++;
			cur_ans += 1LL * cnt[val] * cnt[val] * val;
		}
		while(st < ql[id]){
			int val = a[st];
			cur_ans -= 1LL * cnt[val] * cnt[val] * val;
			cnt[val]--;
			cur_ans += 1LL * cnt[val] * cnt[val] * val;
			++st;
		}
		while(en > qr[id]){
			int val = a[en];
			cur_ans -= 1LL * cnt[val] * cnt[val] * val;
			cnt[val]--;
			cur_ans += 1LL * cnt[val] * cnt[val] * val;
			--en;
		}
		ans[id] = cur_ans;
	}
	for(int i = 0; i < q; i++)
		printf("%I64d\n", ans[i]);
	return 0;
}