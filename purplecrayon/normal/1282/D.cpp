#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int nm=0;
int qry(string s){
    cout << s << "\n"; cout.flush(); nm++;
    int ans; cin >> ans;
    if (ans == 0) { 
        assert(nm <= sz(s)+2);
        exit(0);
    }
    return ans;
}
void solve(){
    char c1='a', c2='b';
    int n1=qry(string(1, c1)), n2=n1;
    int n = n1+1;
    if (n > 300){
        qry(string(n-1, c2));
        assert(false);
    }
    n2 = qry(string(n, c1)), n1 = n-n2;
    if (n2 == n){
        qry(string(n-1, c2));
        assert(false);
    }
    // cout << n1 << ' ' << n2 << "\n";
    //merge c1 into c2
    if (n1 < n2){ 
        swap(n1, n2); swap(c1, c2); 
    }
    string st=string(n2, c2); int pos=0;
    for (int i = 0; i < n1; i++){
        //try adding c1
        while (1){
            string nw=st; nw.insert(pos, string(1, c1));
            int cur=qry(nw); 
            if (sz(nw)+cur == n){
                st=nw; pos++; break;
            }
            pos++;
        }
    }
    qry(st); //aaaab
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}