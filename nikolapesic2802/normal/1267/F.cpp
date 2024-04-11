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
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
const int N=2e5+5;
vector<int> par(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b){par[find(a)]=find(b);}
int main()
{
    iota(all(par),0);
	int n,m,ka,kb;
	cin >> n >> m >> ka >> kb;
	if(n<=kb||m<=ka){
        printf("No\n");
        return 0;
	}
	printf("Yes\n");
	deque<int> a,b;
	vector<int> cnt(n+m+1);
	int aa;
	for(int i=0;i<ka;i++)
        scanf("%i",&aa),aa--,a.pb(aa),cnt[aa]++;
    for(int i=0;i<kb;i++)
        scanf("%i",&aa),aa--,b.pb(aa),cnt[aa]++;
    while(a.size()<m-1)
        a.pb(n-1),cnt[n-1]++;
    while(b.size()<n-1)
        b.pb(n+m-1),cnt[n+m-1]++;
    a.pb(n-1);
    b.pb(n+m-1);
    set<int> gotovi;
    for(int i=0;i<n+m;i++)
        if(cnt[i]==0)
            gotovi.insert(i);
    int lastA,lastB;
    while(gotovi.size()&&a.size()+b.size()>1){
        int tr=*gotovi.begin();
        gotovi.erase(gotovi.begin());
        if(tr<n){
            if(b.size()){
                lastA=tr;
                printf("%i %i\n",tr+1,b.front()+1);
                cnt[b.front()]--;
                if(cnt[b.front()]==0)
                    gotovi.insert(b.front());
                b.pop_front();
            }
        }
        else{
            if(a.size()){
                lastB=tr;
                printf("%i %i\n",tr+1,a.front()+1);
                cnt[a.front()]--;
                if(cnt[a.front()]==0)
                    gotovi.insert(a.front());
                a.pop_front();
            }
        }
    }
    return 0;
}