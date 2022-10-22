#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

struct Tree {
	typedef int T;
	const T LOW = -1234567890;
	T f(T a, T b) { return max(a, b); }

	int n;
	vector<T> s;
	Tree() {}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int a, int b) { return que(1, a, b, 0, n); }
	T que(int pos, int a, int b, int x, int y) {
		if (a >= b) return LOW;
		if (a == x && b == y) return s[pos];
		int m = (x + y) / 2;
		return f(que(2 * pos, a, min(b, m), x, m),
				que(2 * pos + 1, max(a, m), b, m, y));
	}
};

int n,m,k,q;

vi AC;
int start[1000000];
int ACI[1000000];

vi numbers;

vector<bool> kind;
vi A;

unordered_map<int,int> M;
set<int> S;

ll force[1000000] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    int a,b,c,d;

    cin >> n;

   // n = 400000;

    for(int c1 = 0; c1 < n; c1++){
        string s;
        cin >> s >> a;
        //s = "ADD";
       // a = rand();
        bool kin = 1;
        if(s[1] == 'D'){
            numbers.push_back(a);
            kin = 0;
        }
        A.push_back(a);
        kind.push_back(kin);
    }

    sort(all(numbers));
    m = sz(numbers);
    for(int c1 = 0; c1 < m; c1++){
        M[numbers[c1]] = c1;
    }

    ll latest = n-m;
    for(int c1 = n-1; c1 >= 0; c1--){
        bool b = kind[c1];
        a = A[c1];
        a = M[a];
        if(b == 0){
            start[a] = latest;
        }
        else{
            latest--;
            AC.push_back(a);
        }
    }
    reverse(all(AC));

    for(int c1 = 0; c1 < m; c1++){
        ACI[c1] = n-m;
    }
    for(int c1 = 0; c1 < n-m; c1++){
        ACI[AC[c1]] = c1;
    }
/*
    for(int c1 = 0; c1 < n-m; c1++){
        cout << AC[c1] << " ";
    }cout << "\n";

    for(int c1 = 0; c1 < m; c1++){
        cout << start[c1] << " " << ACI[c1] << "\n";
    }
*/
    Tree st(n-m);
    Tree ST(n-m);

    for(int c1 = 0; c1 < n-m; c1++){
        st.update(c1,-AC[c1]);
        ST.update(c1,AC[c1]);
    }


    ll ans = 1;
    ll lasts = 0;
    for(int c1 = 0; c1 < m; c1++){
        if(start[c1] == n-m){
            lasts++;
        }
        else{
            if(start[c1] == ACI[c1]){
                ans *= 2;
                ans %= big;
            }
            else{
                ll mi = -st.query(start[c1],ACI[c1]);
                ll ma = ST.query(start[c1],ACI[c1]);
                if(mi < c1 && ma > c1){
                    ans = 0;
                }
                if(ma > c1){
                    force[c1] = 1;
                }
                else{
                    force[c1] = 2;
                }
            }
        }
    }

    ll small = big;
    ll big2 = -1;
    for(ll c1 = 0; c1 < m; c1++){
        if(start[c1] != n-m && ACI[c1] == n-m){
            if(force[c1] == 1){
                big2 = max(big2,c1);
            }
            else{
                small = min(small,c1);
            }
        }
    }
    /*
    if(small == big){
        small = -1;
    }
    if(big2 == -1){
        big2 = big;
    }
*/
   // cout << small << " " << big2 <<  "\n";

    lasts = 0;
    for(int c1 = 0; c1 < m; c1++){
        if(start[c1] == n-m && ACI[c1] == n-m){
            if(c1 < small && c1 > big2){
                lasts++;
            }
        }
    }

    ans *= (lasts+1);
    ans %= big;

    cout << ans << "\n";

    return 0;
}