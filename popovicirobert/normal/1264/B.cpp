#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


#if 0
const int MOD = (int) ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}
#endif

using namespace std;

vector <int> sol;
int num[4][4];

void dfs(int nod) {
    //cerr << nod << "\n";
    sol.push_back(nod);
    for(int i = nod - 1; i <= nod + 1; i++) {
        if(i >= 0 && i < 4 && num[nod][i] > 0) {
            num[nod][i]--;
            dfs(i);
            break;
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n = 0;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector <int> cnt(4);
    for(i = 0; i < 4; i++) {
        cin >> cnt[i];
        n += cnt[i];
    }

    auto solve = [&](vector <int> in, vector <int> out, int a, int b) -> void {
        num[1][0] = in[0], num[0][1] = out[0];
        num[2][3] = in[3], num[3][2] = out[3];
        num[2][1] = in[1] - num[0][1];
        num[1][2] = in[2] - num[3][2];

        for(i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                //cerr << num[i][j] << " ";
                if(num[i][j] < 0) {
                    return ;
                }
            }
            //cerr << "\n";
        }
        //cerr << "\n";

        sol.clear();
        dfs(a);



        /*for(int nod = 0; nod < 4; nod++) {
            int cur_in = 0, cur_out = 0;
            for(i = 0; i < 4; i++) {
                cur_in += num[i][nod];
                cur_out += num[nod][i];
            }

            if(cur_in + (a == nod) != cur_out + (b == nod)) {
                return ;
            }
        }*/

        if(sol.size() < n) {
            return ;
        }

        cout << "YES\n";
        for(auto it : sol) {
            cout << it << " ";
        }
        exit(0);
    };

    vector <int> in = cnt, out = cnt;
    for(int a = 0; a < 4; a++) {
        in[a]--;
        for(int b = 0; b < 4; b++) {
            out[b]--;
            //cerr << a << " " << b << "\n";
            solve(in, out, a, b);
            //cerr << a << " " << b << "\n";
            out[b]++;
        }
        in[a]++;
    }

    cout << "NO";

    return 0;
}