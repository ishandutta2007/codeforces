#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;

int n;
int sp;

int ask(int l, int r) {
	if (l > r) swap(l, r);
	cout << "? " << l << ' ' << r << '\n' << flush;
	int ret;
	cin >> ret;
	return ret;
}

void answer(int ans) {
	cout << "! " << ans << '\n' << flush;
	exit(0);
}

int sgn(int x) {
	return int(x>0) - int(x<0);
}

void work(int near, int far) {
	if (near == far) { answer(near); return; }
	int mid = (near+far+(far<near))/2;
	if (ask(sp, mid) == sp) { work(near, mid); return; }
	else { work(mid + sgn(far-near), far); return; }
}

int main()
{
	cppio();
	cin >> n;

	sp = ask(1, n);

	if (sp == 1) work(2, n);
	else if (sp == n) work(n-1, 1);
	else {
		int tmp = ask(1, sp);
		if (tmp == sp) work(sp-1, 1);
		else work(sp+1, n);
	}

	return 0;
}