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

pair <int,int> ask (vector <int> pos){

    cout << "? ";
    for(int i=0;i<pos.size();i++){
        cout << pos[i] << " ";
    }
    cout << endl; // cout.flush();
    int poz, val;
    cin >> poz >> val;
    return {poz,val};
}



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int n,k,poz,val,cnt,mic=0;
   // ios::sync_with_stdio(false);
   // cin.tie(0), cout.tie(0);
   cin >> n >> k;
   vector <int> pos(k);
   iota(pos.begin(),pos.end(),1);
   auto cur = ask(pos);
   cnt=0;
   poz=cur.first;
   val=cur.second;
   for(int i=1;i<=k;i++){
    if(i!=poz){
        pos[i-1]= k+1;
        cur=ask(pos);
        if(val==cur.second)
            cnt++;
        else if(val<cur.second)
            mic=-1;
            else
            mic=1;
        pos[i-1]=i;


    }
   }
   if(mic==0){
      pos[poz-1]=k+1;
      cur=ask(pos);

      if(val<cur.second)
        mic=-1;
      else mic=1;
   }

    if(mic==1)
        cout << "! " << cnt+1;
    else cout << "! " << k-cnt;

    return 0;
}