#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

template<class T>
struct KMP {
	template<class I>
	KMP(I begin, I end) : word(begin, end) {
		table.resize(word.size() + 1, 0);
		table[0] = -1;
		for(unsigned i = 2; i <= word.size(); i++)
			for(int j = table[i - 1]; j >= 0; j = table[j])
				if(word[i - 1] == word[j]) {
					table[i] = j + 1;
					break;
				}
	}

	template<class I>
	vector<int> findAll(I begin, I end) {
		vector<int> res;
		unsigned tp = 0, tl = (end - begin), wp = 0;
		while(tp + wp < tl) {
			if(wp < word.size() && word[wp] == *(begin + tp + wp)) {
				if(++wp == word.size())
					res.push_back(tp); // Break here for "findFirst".
			} else {
				tp += wp - table[wp];
				wp = max(table[wp], 0);
			}
		}
		return res;
	}

	vector<T> word; // Search word.
	vector<int> table; // Partial match table.
};

ll n,m,T,k,d;
const ll big = 1000000007;

bool ignored[3001] = {0};
int frst = -1;

vector<string> from;
vector<string> to;
vi N;
string s;

string ff;
string tt;

vi L;
vi R;

bool validate(int i){
    if(i+L[frst] < 0 || i+L[frst] >= N[frst])return 0;
    char a = from[frst][i+L[frst]];
    char b = to[frst][i+L[frst]];
    for(int c1 = frst+1; c1 < n; c1++){
        if(ignored[c1])continue;
        int j = i+L[c1];
        if(j < 0 || j >= N[c1])return 0;
        if(from[c1][j] != a || to[c1][j] != b)return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;

    for(int c1 = 0; c1 < n; c1++){
        cin >> s;
        from.push_back(s);
        N.push_back(s.length());
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> s;
        to.push_back(s);
    }

    for(int c1 = 0; c1 < n; c1++){
        L.push_back(n);
        R.push_back(-1);

        for(int c2 = 0; c2 < from[c1].length(); c2++){
            if(L[c1] == n && from[c1][c2] != to[c1][c2]){
                L[c1] = c2;
            }
            if(from[c1][c2] != to[c1][c2]){
                R[c1] = c2;
            }
        }

        if(L[c1] == n){
            ignored[c1] = 1;
        }
        else{
            if(frst == -1)frst = c1;
        }

    }

    int d = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(ignored[c1])continue;
        d = max(d,R[c1]-L[c1]+1);
    }

    for(int c1 = 0; c1 < d; c1++){
        if(!validate(c1)){
            cout << "NO\n";
            return 0;
        }
    }

    while(validate(-1)){
        for(int c1 = 0; c1 < n; c1++){
            if(ignored[c1])continue;
            L[c1]--;
        }
        d++;
    }

    while(validate(d)){
        for(int c1 = 0; c1 < n; c1++){
            if(ignored[c1])continue;
            R[c1]++;
        }
        d++;
    }

    ff = "";
    tt = "";
    for(int c1 = L[frst]; c1 <= R[frst]; c1++){
        ff += from[frst][c1];
        tt += to[frst][c1];
    }
    KMP<char> kmp(ff.begin(), ff.end());
    for(int c1 = 0; c1 < n; c1++){
        vector<int> occ = kmp.findAll(from[c1].begin(), from[c1].end());
        if(sz(occ) == 0){
            continue;
        }
        a = occ[0];

        for(int c2 = a; c2 < a+ff.length(); c2++){
            assert(c2 < N[c1]);
            from[c1][c2] = tt[c2-a];
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        if(from[c1] != to[c1]){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    cout << ff << "\n" << tt << "\n";

    return 0;
}