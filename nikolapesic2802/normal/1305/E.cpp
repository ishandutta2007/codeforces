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
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=10,L=80;
vector<int> tr;
map<int,int> done;
void gen(int t,int l){
    if(t==N){
        int cnt=0;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                for(int k=j+1;k<N;k++)
                    if(tr[i]+tr[j]==tr[k])
                        cnt++;
        if(!done[cnt]){
            done[cnt]=1;
            printf("%i: ",cnt);
            cout << tr << endl;
        }
        return;
    }
    for(int i=l+1;i<L;i++)
        tr.pb(i),gen(t+1,i),tr.pop_back();
}
int cnt[10001];
void solve(){
    int mx=1e9;
    int n,m;
    scanf("%i %i",&n,&m);
    vector<int> a(n);
    iota(all(a),1);
    ll sol=0;
    for(int i=0;i<n;i++){
        sol+=cnt[a[i]];
        for(int j=i-1;j>=0;j--)
            cnt[a[i]+a[j]]++;
    }
    if(sol<m){
        printf("-1\n");
        return;
    }
    if(sol==m){
        for(auto p:a)
            printf("%i ",p);
        return;
    }
    for(int i=n-1;i>=0;i--){
        int pre=i;
        ll dist=sol-m;
        int mogu=pre/2;
        if(mogu<=dist){
            m+=mogu;
            a[i]=mx-(n-i)*10000;
            continue;
        }
        while(dist)
            dist--,a[i]+=2;
        for(auto p:a)
            printf("%i ",p);
        return;
    }
    for(auto p:a)
        printf("%i ",p);
    return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	//gen(0,0);
	return 0;
}