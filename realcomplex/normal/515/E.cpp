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

const int L = 1<<18;
ll D[L];
ll H[L];
ll F[L];
ll S[L];

ll T1[L*2][2];
ll T2[L*2][2];

void build(int node,int a,int b){
	if(a>b)
		return;
	if(a==b){
		T1[node][0] = F[a];
		T1[node][1] = a;
		T2[node][0] = S[b];
		T2[node][1] = b;
		return;
	}
	build(node*2,a,(a+b)/2);
	build(node*2+1,1+(a+b)/2,b);
	if(T1[node*2][0] > T1[node*2+1][0])
		T1[node][0] = T1[node*2][0],T1[node][1] = T1[node*2][1];
	else
		T1[node][0] = T1[node*2+1][0],T1[node][1] = T1[node*2+1][1];
	
	if(T2[node*2][0] > T2[node*2+1][0])
		T2[node][0] = T2[node*2][0],T2[node][1] = T2[node*2][1];
	else
		T2[node][0] = T2[node*2+1][0],T2[node][1] = T2[node*2+1][1];
	
}

int maxt(int node,int a,int b,int l,int r){
	if(a > b)
		return 0;
	if(a > r)
		return 0;
	if(b < l)
		return 0;
	if(a >= l and b <= r){
		return node;
	}
	int q1 = maxt(node*2,a,(a+b)/2,l,r);
	int q2 = maxt(node*2+1,1+(a+b)/2,b,l,r);
	if(T1[q1][0] > T1[q2][0])
		return q1;
	else
		return q2;
}
int maxs(int node,int a,int b,int l,int r){
	if(a > b)
		return 0;
	if(a > r)
		return 0;
	if(b < l)
		return 0;
	if(a >= l and b <= r){
		return node;
	}
	int q1 = maxs(node*2,a,(a+b)/2,l,r);
	int q2 = maxs(node*2+1,1+(a+b)/2,b,l,r);
	if(T2[q1][0] > T2[q2][0])
		return q1;
	else
		return q2;
}


int main(){
	fastIO;
	T2[0][0] = (ll)-1e18;
	T1[0][0] = (ll)-1e18;
	int n,q;
	cin >> n >> q;
	int k = n*2;
	for(int i = 0;i<n;i++){
		cin >> D[i];
		D[i+n] = D[i];
	}
	for(int i = 1;i<k;i++)
		D[i] += D[i-1];
	for(int i = 0;i<n;i++){
		cin >> H[i];
		H[i+n] = H[i];
	}
	for(int i = 0;i<k;i++){
		F[i] = (i == 0 ? 0 : D[i-1]) + H[i] * 2;
		S[i] = (i == 0 ? 0 : -D[i-1]) + H[i] * 2;
	}
	build(1,0,L-1);
	int il,ir;
	int i1,i2,i3;
	int j1,j2,j3;
	ll ans ;
	while(q--){
		cin >> il >> ir;
		--il;
		--ir;
		if(il <= ir){
			il += n;
		}
		swap(il,ir);
		il++;
		ir--;
		i1 = T1[maxt(1,0,L-1,il,ir)][1];
		i2 = T1[maxt(1,0,L-1,il,i1-1)][1];
		i3 = T1[maxt(1,0,L-1,i1+1,ir)][1];
		j1 = T2[maxs(1,0,L-1,il,ir)][1];
		j2 = T2[maxs(1,0,L-1,il,i1-1)][1];
		j3 = T2[maxs(1,0,L-1,i1+1,ir)][1];
		ans = (ll)-1e18;
		if(i1 != j1 and i1 >= il and j1 <= ir and i1 <= ir and j1 >= il) ans = max(ans,F[i1]+S[j1]);
		if(i1 != j2 and i1 >= il and j2 <= ir and i1 <= ir and j2 >= il) ans = max(ans,F[i1]+S[j2]);
		if(i1 != j3 and i1 >= il and j3 <= ir and i1 <= ir and j3 >= il) ans = max(ans,F[i1]+S[j3]);
		if(i2 != j1 and i2 >= il and j1 <= ir and i2 <= ir and j1 >= il) ans = max(ans,F[i2]+S[j1]);
		if(i2 != j2 and i2 >= il and j2 <= ir and i2 <= ir and j2 >= il) ans = max(ans,F[i2]+S[j2]);
		if(i2 != j3 and i2 >= il and j3 <= ir and i2 <= ir and j3 >= il) ans = max(ans,F[i2]+S[j3]);
		if(i3 != j1 and i3 >= il and j1 <= ir and i3 <= ir and j1 >= il) ans = max(ans,F[i3]+S[j1]);
		if(i3 != j2 and i3 >= il and j2 <= ir and i3 <= ir and j2 >= il) ans = max(ans,F[i3]+S[j2]);
		if(i3 != j3 and i3 >= il and j3 <= ir and i1 <= ir and j3 >= il) ans = max(ans,F[i3]+S[j3]);
		cout << ans << "\n";
	}
	return 0;	
}