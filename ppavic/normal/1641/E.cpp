#include <cstdio>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

typedef vector < int > vi;
typedef long long ll;

const int N = 1e5 + 500;
const int MOD = 998244353;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) 
			ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

const int mod = 998244353;
const int root = 565042129;
const int root_1 = 950391366;
const int root_pw = 1 << 20;

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = pot(n, MOD - 2);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vi mul(vi A, vi B){ // ovdje NTT
	int pot = (int)A.size() + (int)B.size() - 1;
	int prav = (int)A.size() + (int)B.size() - 1;
	while(pot & (pot - 1)) pot++;
	while((int)A.size() < pot) A.PB(0);
	while((int)B.size() < pot) B.PB(0);
	fft(A, 0), fft(B, 0);
	vi C;
	for(int i = 0;i < pot;i++)
		C.PB(mul(A[i], B[i]));
	fft(C, 1);
	while((int)C.size() > prav) C.pop_back();
	return C;
}

vi special_mul(vi A, vi B){
	if((int)A.size() == 1) return {mul(A[0], B[0])};
	vi C; C.resize((int)A.size() + (int)B.size() - 1);
	int mid = (int)A.size() / 2;
	vi Al, Ar, Bl, Br;
	for(int i = 0;i < (int)A.size();i++){
		if(i < mid) Al.PB(A[i]), Bl.PB(B[i]);
		else		Ar.PB(A[i]), Br.PB(B[i]);
	}
	vi medu = mul(Al, Br);
	vi Cl = special_mul(Al, Bl);
	vi Cr = special_mul(Ar, Br);
	for(int i = 0;i < (int)Cl.size();i++) C[i] = Cl[i];
	for(int i = 0;i < (int)Cr.size();i++) C[i + 2 * mid] = Cr[i];
	for(int i = 0;i < (int)medu.size();i++) C[i + mid] = add(C[i + mid], medu[i]);
	return C;
}

int A[N], uz[N], n, m, pt2[N];
int pP[N], pS[N], cur, sveA = 0; 
vi P, S, R;

void precompute(){
	pt2[0] = 1;
	for(int i = 1;i < N;i++)
		pt2[i] = mul(2, pt2[i - 1]);
}

int main(){
	precompute();
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i), sveA = add(sveA, A[i]);
	for(int j = 0;j < m;j++){
		int x; scanf("%d", &x);
		uz[x - 1] = 1;
	}
	for(int i = 0;i < n;i++){
		P.PB(pt2[cur]);
		cur += uz[i];
	}
	cur = 0;
	for(int i = n - 1;i >= 0;i--){
		S.PB(pt2[cur]);
		cur += uz[i];
	}
	reverse(S.begin(), S.end());
	for(int i = 0;i < n;i++)
		pP[i] = add(i ? pP[i - 1] : 0, P[i]);
	for(int i = n - 1;i >= 0;i--)
		pS[i] = add(pS[i + 1], S[i]);
	R = special_mul(P, S);
	int ans = 0;
	for(int i = 0;i < n;i++){
		int kofa = R[2 * i];
		if(2 * i < n){
			if(2 * i + 1 < n)
				kofa = add(kofa, pS[2 * i + 1]);
		}
		else{
			if(n - 2 * (n - i - 1) - 2 >= 0)
				kofa = add(kofa, pP[n - 2 * (n - i - 1) - 2]);	
		}
		kofa = add(kofa, n - max(i, n - i - 1) - 1);
		ans = add(ans, mul(kofa, A[i]));
	}
	int inv_sve = pot(pt2[m], MOD - 2);
	sveA = mul(sveA, n);
	ans = sub(ans, sveA);
	ans = mul(ans, inv_sve); 
	ans = mul(ans, mul(pt2[m], pot(sub(pt2[m], 1), MOD - 2)));
	printf("%d\n", ans);
}