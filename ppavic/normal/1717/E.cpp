#include <cstdio>
#include <algorithm>
#include <vector>

#define PB push_back

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;
const int MOD = 1e9 + 7;


inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}


inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

inline int dijeli(int A, int B){
	return mul(A, pot(B, MOD - 2));
}

// copied from https://codeforces.com/blog/entry/10119

int lp[N];
int phi[N];
vector < int > pr;


void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

// end

int n;
vector < int > divv[N];

void precompute(){
	for(int i = 1;i < N;i++)
		for(int j = 2 * i;j < N;j += i)
			divv[j].PB(i);
}

int main(){
	calc_sieve();
	precompute();
	scanf("%d", &n);
	int sol = 0;
	for(int c = 1;c <= n - 2;c++){
		int S = n - c, tmp = 0;
		for(int &g : divv[S]){
			int Sg = S / g;
			tmp = add(tmp, mul(phi[Sg], dijeli(g, __gcd(c, g))));
		}
		sol = add(sol, mul(tmp, c));
	}
	printf("%d\n", sol);
	return 0;
}