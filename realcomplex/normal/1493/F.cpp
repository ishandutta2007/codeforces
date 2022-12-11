#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int h, int w, int i1, int j1, int i2, int j2){
    cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
    int res;
    cin >> res;
    return res;
}

const int N = 1005;
int ca[N], cb[N];


int main(){
    int n, m;
    cin >> n >> m;
    int cc;
    int sz;
    bool valid;
    int g;
    for(int i = n; i >= 1; i -- ){
        if(n % i != 0 || ca[i] != 0) continue;
        cc = n / i;
        valid = false;
        if(cc % 2 == 1){
            if(cc == 1) valid = true;
            else{
                sz = cc / 2;
                valid = (ask(sz*i,m,1,1,1+sz*i,1) & ask(sz*i,m,1,1,1+(sz+1)*i,1));
            }
        }
        else{
            sz = cc/2;
            valid = ask(sz*i,m,1,1,1+sz*i,1);
            if(sz > 1)
                valid &= ask((sz-1)*i,m,1,1,1+(sz-1)*i,1);
        }
        if(valid){
            ca[i]=1;
            for(int j = 1; j <= n; j ++ ){
                if(ca[j] == 1){
                    g = __gcd(i, j);
                    for(int q = g; q <= n; q += g){
                        if(n % q == 0){
                            ca[q] = 1;
                        }
                    }
                }
            }
        }
        else{
            ca[i]=2;
            for(int j = 1; j < i ; j ++ ){
                if(i % j == 0) ca[j] = 2;
            }
        }
    }
    for(int i = m; i >= 1; i -- ){
        if(m % i != 0 || cb[i] > 0) continue;
        cc = m / i;
        valid = false;
        if(cc % 2 == 1){
            if(cc == 1) valid = true;
            else{
                sz = cc / 2;
                valid = (ask(n,sz*i,1,1,1,1+sz*i) & ask(n,sz*i,1,1,1,1+(sz+1)*i));
            }
        }
        else{
            sz = cc/2;
            valid = ask(n,sz*i,1,1,1,1+sz*i);
            if(sz > 1){
                valid &= ask(n,(sz-1)*i,1,1,1,1+(sz-1)*i);
            }
        }
        if(valid){
            cb[i]=1;
            for(int j = 1; j <= m; j ++ ){
                if(cb[j] == 1){
                    g = __gcd(i, j);
                    for(int w = g; w <= m; w += g){
                        if(m % w == 0){
                            cb[w] = 1;
                        }
                    }
                }
            }
        }
        else{
            cb[i]=2;
            for(int j = 1; j < i; j ++ ){
                if(i % j == 0){
                    cb[j]=2;
                }
            }
        }
    }
    int na = 0, nb = 0;
    for(int i = 1; i <= n; i ++ ) na += (ca[i]==1);
    for(int i = 1; i <= m; i ++ ) nb += (cb[i]==1);
    cout << "! " << na * 1ll * nb << endl;
    return 0;
}