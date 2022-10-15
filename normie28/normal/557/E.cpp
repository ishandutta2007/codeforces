
// Problem : E. Ann and Half-Palindrome
// Contest : Codeforces - Codeforces Round #311 (Div. 2)
// URL : https://codeforces.com/problemset/problem/557/E
// Memory Limit : 512 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILENAME "cseq"
#define EXTENSION_IN "inp"
#define EXTENSION_OUT "out"
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair
typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
#define ofile freopen(FILENAME "." EXTENSION_IN,"r",stdin);freopen(FILENAME "." EXTENSION_OUT,"w",stdout)
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
int n,m,k,c[501],t,t1,i,j;
 
char s[5010];
bool halfPal[5010][5010];
int tot, len;
int trie[25000001][3];
 
void push(int st){
    int cur = 0;
    for (int i = st; i < len; ++i){
        int nxt = s[i] - 'a';
        if (!trie[cur][nxt]){
            trie[cur][nxt] = tot++;
        }
        cur = trie[cur][nxt];
        if (halfPal[st][i]) trie[cur][2]++;
    }
}
 
char res[5100];
int pos;
 
bool dfs(int s, int &k){
    k -= trie[s][2];
    if (k <= 0) return true;
    if (trie[s][0] && dfs(trie[s][0], k))
    {
        res[pos++] = 'a';
        return true;
    }
    if (trie[s][1] && dfs(trie[s][1], k)){
        res[pos++] = 'b';
        return true;
    }
    return false;
}
 
int main()
{
//	ofile;
	fio;
	cin>>s;
    len = strlen(s);
 
    for (int i = 1; i <= len; ++i){
        for (int j = 0; j + i - 1 < len; ++j){
            if (s[j] != s[j + i - 1]) continue;
            if (j + 2 > j + i - 3 || halfPal[j + 2][j + i - 3])
                halfPal[j][j + i - 1] = true;
        }
    }
 
    tot = 1;
    for (int i = 0; i < len; ++i)
        push(i);
 
    int k;
    cin>>k;
    dfs(0, k);
    while (pos) cout<<res[--pos];
    cout<<endl;
}