 // Problem : E. Neatness 
 // Contest : Codeforces - Codeforces Round #209 (Div. 2) 
 // URL : https://codeforces.com/contest/359/problem/E 
 // Memory Limit : 256 MB 
 // Time Limit : 2000 ms 
 // Powered by CP Editor (https://github.com/cpeditor/cpeditor)  
 /*  A Submission by $%U%$  
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$ 
 */ 
 #include <bits/stdc++.h> 
 using namespace std; 
 #include <ext/pb_ds/assoc_container.hpp> 
 #include <ext/pb_ds/tree_policy.hpp> 
 using namespace __gnu_pbds; 
 #define fef(i,a,b) for(ll i=a;i<=b;i++) 
 #define rer(i,a,b) for(ll i=b;i>=a;i--) 
 #define wew while(true) 
 #pragma comment(linker, "/stack:200000000") 
 #pragma GCC optimize("Ofast") 
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
 #define FILE_IN "cseq.inp" 
 #define FILE_OUT "cseq.out" 
 #define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout) 
 #define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
 #define nfio cin.tie(0);cout.tie(0) 
 #define max(x,y) (((x)>(y))?(x):(y)) 
 #define min(x,y) (((x)<(y))?(x):(y)) 
 #define ord(a,b,c) ((a>=b)and(b>=c)) 
 #define MOD (ll(1000000007))
 #define MAX 300001 
 #define mag 320 
 #define p1 first 
 #define p2 second.first 
 #define p3 second.second 
 #define fi first
 #define se second
 #define pow2(x) (ll(1)<<x)
 #define pii pair<int,int> 
 #define piii pair<int,pii>
 #define For(i,__,___) for(int i=__;i<=___;i++) 
 #define Rep(i,__,___) for(int i=__;i>=___;i--)
 #define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> 
 #define endl "\n" 
 #define bi BigInt 
 typedef long long ll; 
 //---------END-------//
int x1, x2, a, b, chk;
 
int main() {
    cin >> x1 >> x2 >> a >> b;
 
    if(a <= x2 - x1 && x2 - x1 <= b) {
        cout << "FIRST" << endl;
        cout << x2 << endl;
        return 0;
    }
 
    if(a + b < 0) {
        swap(x1, x2);
        swap(a, b);
        a = -a;
        b = -b;
        chk = 1;
    }
 
    int diff = x2 - x1;
    int sum = a + b;
 
    if(a <= 0) {
        cout << "DRAW" << endl;
        return 0;
    }
    if(diff < 0) {
        cout << "DRAW" << endl;
        return 0;
    }
    if(a <= diff % sum && diff % sum <= b) {
        cout << "FIRST" << endl;
        if(chk) cout << x2 - diff % sum << endl;
        else cout << x1 + diff % sum << endl;
        return 0;
    }
    if(diff % sum == 0) {
        cout << "SECOND" << endl;
        return 0;
    }
    cout << "DRAW" << endl;
}