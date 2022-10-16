#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int S=62,mod=998244353,L=11;
int get(char c){
    if(c>='a'&&c<='z')return c-'a';
    if(c>='A'&&c<='Z')return c-'A'+26;
    return c-'0'+52;
}
int cnt[L][S][S],dp[S][S][S];
int get(int a,int b,int c,int d){if(a==b&&b==c&&c==d)return 1;if(a==b&&b==c)return 4;if(b==c&&c==d)return 4;if(a==b&&c==d)return 6;if(a==b||b==c||c==d)return 12;return 24;}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sol=0;
    cin >> n;
    map<string,bool> was;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        string t=s;
        reverse(all(t));
        if(!was[s])
            cnt[s.size()][get(s.front())][get(s.back())]++,was[s]=1;
        if(!was[t])
            cnt[t.size()][get(t.front())][get(t.back())]++,was[t]=1;
    }
    for(int o=3;o<=10;o++){
        for(int i=0;i<S;i++)for(int j=i;j<S;j++)for(int k=j;k<S;k++)dp[i][j][k]=0;
        for(int i=0;i<S;i++)for(int j=i;j<S;j++)for(int k=j;k<S;k++)for(int w=0;w<S;w++)dp[i][j][k]=(dp[i][j][k]+(ll)cnt[o][i][w]*cnt[o][j][w]%mod*cnt[o][k][w]%mod)%mod;
        for(int i=0;i<S;i++)for(int j=i;j<S;j++)for(int k=j;k<S;k++)for(int w=k;w<S;w++)sol=(sol+(ll)dp[i][j][k]*dp[i][j][w]%mod*dp[i][k][w]%mod*dp[j][k][w]%mod*get(i,j,k,w)%mod)%mod;
    }
    cout << sol;
}