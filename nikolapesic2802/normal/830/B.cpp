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

const int N=1e5+5;
vector<int> sum(N);
void add(int i,int x){
    for(;i<N;i+=i&(-i))
        sum[i]+=x;
}
int getpre(int i){
    int ans=0;
    for(;i;i-=i&(-i))
        ans+=sum[i];
    return ans;
}
int get(int l,int r){
    return getpre(r)-(l!=0?getpre(l-1):0);
}
ll sol;
int main()
{
	int n,a;
	scanf("%i",&n);
	vector<set<int> > pos(1e5+5);
	for(int i=1;i<=n;i++)
        scanf("%i",&a),pos[a].insert(i),add(i,1);
    int lst=1;
    for(auto &p:pos)
    {
        auto it=p.lower_bound(lst);
        while(it!=p.end()){
            int i=(*it);
            sol+=get(lst,i);
            add(i,-1);
            lst=i;
            p.erase(it);
            it=p.lower_bound(lst);
        }
        for(auto i:p){
            if(i<lst)
            sol+=getpre(i)+get(lst,n);
            else
                sol+=get(lst,i);
            add(i,-1);
            lst=i;
        }
    }
    printf("%lld\n",sol);
    return 0;
}