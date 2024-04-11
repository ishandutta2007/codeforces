#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;
typedef pair < pii, int > ppi;

const int N = 1e5 + 500;
const int OFF = (1 << 17);
const int INF = 0x3f3f3f3f;

int n, q, A[N], L[N], R[N];
int T[2 * OFF][3], qL[N], qR[N], qK[N], qS[N];

vector < int > qP;
vector < ppi > v;

bool cmp(int i, int j){
	return qK[i] < qK[j];
}

void update(int i, int x, int fl){
	T[OFF + i][fl] = max(T[OFF + i][fl], x);
	for(i = (i + OFF) / 2 ; i ; i /= 2)
		T[i][fl] = max(T[2 * i][fl], T[2 * i + 1][fl]);
}

int query(int i, int a, int b, int lo, int hi, int fl){
	if(lo <= a && b <= hi) return T[i][fl];
	if(a > hi || b < lo) return -INF;
	return max(query(2 * i, a, (a + b) / 2, lo, hi, fl), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, fl));
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i), T[OFF + i][2] = -A[i];
	for(int i = OFF - 1; i ; i--)
		T[i][2] = max(T[2 * i][2], T[2 * i + 1][2]);
	stack < int > S;
	for(int i = 0;i < n;i++){
		for(;!S.empty() && A[S.top()] >= A[i];S.pop());
		L[i] = (S.empty() ? 0 : S.top() + 1);
		S.push(i);
	}
	for(;!S.empty();S.pop());
	for(int i = n - 1;i >= 0;i--){
		for(;!S.empty() && A[S.top()] > A[i];S.pop());
		R[i] = (S.empty() ? n - 1 : S.top() - 1);
		S.push(i);
	}
	for(int i = 0;i < n;i++){
		v.PB({{R[i] - L[i] + 1, L[i]}, A[i]});
	}
	scanf("%d", &q);
	for(int i = 0;i < q;i++){
		scanf("%d%d%d", qL + i, qR + i, qK + i);
		qL[i]--, qR[i]--; qP.PB(i);
	}
	sort(qP.rbegin(), qP.rend(), cmp);
	sort(v.rbegin(), v.rend());
	int j = 0;
	for(int i : qP){
		while(j < (int)v.size() && v[j].X.X >= qK[i]){
			int l = v[j].X.Y; int r = l + v[j].X.X - 1;
			update(l, v[j].Y, 0); update(r, v[j].Y, 1);
			j++;
		}
		qS[i] = -query(1, 0, OFF - 1, qL[i], qR[i], 2);
		qS[i] = max(qS[i], query(1, 0, OFF - 1, qL[i], qR[i] - qK[i] + 1, 0));
		qS[i] = max(qS[i], query(1, 0, OFF - 1, qL[i] + qK[i] - 1, qR[i], 1));
	}
	for(int i = 0;i < q;i++)
		printf("%d\n", qS[i]);
	return 0;
}