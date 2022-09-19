#include <bits/stdc++.h>

using namespace std;

const int _ = 1 << 20 , mod = 998244353 , G = 3;
int upd(int x) {
    return x + (x >> 31 & mod);
}
int add(int x , int y) {
    return upd(x + y - mod);
}
int sub (int x , int y){
    return upd(x - y);
}
int mul (int a, int b) {
    return 1ll*a*b%mod;
}
int poww(long long a , int b) {
    int tms = 1;
    while (b) {
        if(b & 1) tms = tms * a % mod;
        a = a * a % mod; b >>= 1;}
    return tms;
}

int dir[_] , need , invnd , w[_];
void init(int len){
	static int L = 1; need = 1;
	while (need < len) need <<= 1;
	invnd = poww(need , mod - 2);
	for (int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for (int &i = L ; i < need ; i <<= 1) {
        w[i] = 1;
        int wn = poww(G , mod / i / 2);
        for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % mod;
    }
}

void dft(vector < int > &arr , int tmod){
	arr.resize(need);
	for (int i = 1 ; i < need ; ++i) {
        if (i < dir[i]) swap(arr[i] , arr[dir[i]]);
	}
	for(int i = 1 ; i < need ; i <<= 1) {
		for (int j = 0 ; j < need ; j += i << 1) {
			for (int k = 0 ; k < i ; ++k) {
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % mod;
				arr[j + k] = add(x , y); arr[i + j + k] = sub(x , y);
			}
		}
	}
	if(tmod == -1) {
        reverse(arr.begin() + 1 , arr.end());
        for(auto &t : arr) {
            t = 1ll * t * invnd % mod;
        }
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    init(a.size()+b.size());
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    dft(fa, 1);
    dft(fb, 1);
    for (int i = 0; i < need; i++) {
        fa[i] = 1ll * fa[i] * fb[i] % mod;
    }
    dft(fa, -1);
    return fa;
}
const int c=200002;
int n, fakt[c], inv[c], sum;
vector<int> a, b, ans;
int binom (int a , int b) {
    if (b<0 || b>a) {
        return 0;
    }
    return 1ll * fakt[a] * inv[b] % mod * inv[a - b] % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]= 1ll*fakt[i-1]*i%mod;
        inv[i]=poww(fakt[i], mod-2);
    }

    cin >> n;
    a.push_back(1);
    for (int i=1; i<=n; i++) {
        int fel, le;
        cin >> fel >> le;
        int si=a.size(), kov=a.size()+fel-le;

        b.clear();
        for (int i=le-si; i<=fel+si; i++) {
            b.push_back(binom(fel+le, i));
        }
        ans=multiply(a, b);

        a.clear();
        for (int i=si; i<2*si+fel-le; i++) {
            a.push_back(ans[i]);
        }
    }

    for (int i:a) {
        sum=add(sum, i);
    }
    cout << sum << "\n";
    return 0;
}