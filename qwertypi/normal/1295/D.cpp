#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

template <class T>
T powmod(T a, ll b, ll m){
	T res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

ll modinv(ll a, ll m){
	ll b = a % m;
	a = m;
	ll x1 = 1, x2 = 0;
	ll y1 = 0, y2 = 1;
	while(b){
		ll d = a / b;
		x1 -= y1 * d;
		x2 -= y2 * d;
		a -= b * d;
		swap(x1, y1);
		swap(x2, y2);
		swap(a, b);
	}
	return (x2 + m) % m;
}

pair<ll, ll> Ext(ll a, ll b){
	ll x1 = 1, x2 = 0;
	ll y1 = 0, y2 = 1;
	if(a < b){
		swap(a, b);
	}
	while(b){
		ll d = a / b;
		x1 -= y1 * d;
		x2 -= y2 * d;
		a -= b * d;
		swap(x1, y1);
		swap(x2, y2);
		swap(a, b);
	}
	return pair<ll, ll>{x1, x2};
}

void genPrime(ll n, vector<ll> & _lp){
    _lp.resize(n + 1);
	vector<ll> primes;
	for (int i = 2; i <= _lp.size(); i++) {
	    if(_lp[i] == 0){
	        _lp[i] = i;
	        primes.push_back(i);
	    }
	    for(int j = 0; j < primes.size() && primes[j] <= _lp[i] && i * primes[j] <= _lp.size(); j++){
	    	_lp[i * primes[j]] = primes[j];
		}
	}
}


bool MR(ll n){
    if(n == 1){
        return false;
    }
	ll d = n - 1;
	int ord = 0;
	while(d % 2 == 0){
		ord++;
		d /= 2;
	}
	for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
		if(n == a){
			return true;
		}
		ll x = powmod<ll>(a, d, n);
		if(x == 1){
			goto End;
		}
		for(int i=0;i<=ord;i++){
			if(x == n - 1){
				goto End;
			}
			x = (x * x) % n;
		}
		return false;
		End:;
	}
	return true;
}

vector<pair<ll, ll>> PF(ll n, vector<ll> & _lp){
    vector<pair<ll, ll>> res;
    ll k = ceil(sqrt(n));
    if(_lp.size() < k + 1){
        cout << "Bound Error";
        exit(0);
    }
    int cnt_2 = 0;
    while(n % 2 == 0){
        n /= 2;
        cnt_2++;
    }
    if(cnt_2) res.push_back(make_pair(2, cnt_2));
    int i = 3;
    while(i * i <= n){
        if(_lp[i] == i && n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            res.push_back(make_pair(i, cnt));
            if(MR(n)){
            	break;
			}
        }
        i += 2;
    }
    if(n != 1){
        res.push_back(make_pair(n, 1));
    }
    return res;
}

ll phi(ll n, vector<ll> & _lp){
    ll res = n;
    for(auto I : PF(n, _lp)){
        res = res / I.first * (I.first - 1);
    }
    return res;
}

vector<int> lp;
int32_t main(){
	genPrime(100000, lp);
	int t;
	cin >> t;
	while(t--){
		int a, m;
		cin >> a >> m;
		int g = __gcd(a, m);
		a /= g;
		m /= g;
		cout << phi(m, lp) << endl;
	} 
}