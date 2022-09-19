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
    while (fa.size()>1 && fa.back()==0) {
        fa.pop_back();
    }
    return fa;
}







int n, si;
map<int, int> m;
vector<vector<int> > sz;
vector<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto x:m) {
        int se=x.second;
        s.clear();
        s.resize(se+1, 1);
        sz.push_back(s);
    }
    si=sz.size();
    for (int l=1; l<si; l*=2) {
        for (int i=0; i+l<si; i+=2*l) {
            sz[i]=multiply(sz[i], sz[i+l]);
        }
    }
    cout << sz[0][n/2] << "\n";
    return 0;
}