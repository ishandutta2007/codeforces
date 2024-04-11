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

const int N=2e5+5;
vector<int> mapa(256);
int n,dp[N][6][6];
bool sta[N][6][6];
string s;
int calc(int tr,int a,int b){
    if(tr==n)
        return 0;
    if(dp[tr][a][b]!=-1)
        return dp[tr][a][b];
    dp[tr][a][b]=N;
    int c=mapa[s[tr]];
    if(c==0){
        dp[tr][a][b]=calc(tr+1,b,c);
        sta[tr][a][b]=1;
        return dp[tr][a][b];
    }
    dp[tr][a][b]=calc(tr+1,a,b)+1;
    sta[tr][a][b]=0;
    if((a==1&&b==2&&c==3)||(a==4&&b==5&&c==1))
        return dp[tr][a][b];
    int moze=calc(tr+1,b,c);
    if(moze<dp[tr][a][b])
        dp[tr][a][b]=moze,sta[tr][a][b]=1;
    return dp[tr][a][b];
}
int main()
{
	mapa['o']=1;
	mapa['n']=2;
	mapa['e']=3;
	mapa['t']=4;
	mapa['w']=5;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
        cin >> s;
        n=s.size();
        for(int j=0;j<n;j++)
            for(int k=0;k<6;k++)
                for(int o=0;o<6;o++)
                    dp[j][k][o]=-1;
        printf("%i\n",calc(0,0,0));
        vector<int> ar;
        int a=0,b=0;
        for(int tr=0;tr<n;tr++)
            if(sta[tr][a][b])
                a=b,b=mapa[s[tr]];
            else
                ar.pb(tr+1);
        for(auto p:ar)
            printf("%i ",p);
        printf("\n");

	}
    return 0;
}