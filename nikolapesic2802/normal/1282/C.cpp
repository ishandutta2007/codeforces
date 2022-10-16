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

int main()
{
	int m;
	scanf("%i",&m);
	while(m--){
        int n,t,a,b;
        scanf("%i %i %i %i",&n,&t,&a,&b);
        vector<pair<int,int> > pr(n);
        vector<int> total(2);
        for(int i=0;i<n;i++)
            scanf("%i",&pr[i].s),total[pr[i].s]++;
        for(int i=0;i<n;i++)
            scanf("%i",&pr[i].f);
        sort(all(pr));
        pr.pb({t+1,0});
        vector<int> cnt(2);
        int sol=0;
        int pre=pr[0].f-1;
        if(pre>0){
            int cntExtra=0;
            int mali=total[0],veliki=total[1];
            int ostalo=min(mali,pre/a);
            cntExtra+=ostalo;
            pre-=ostalo*a;
            ostalo=min(veliki,pre/b);
            cntExtra+=ostalo;
            sol=cntExtra;
        }
        for(int i=0;i<n;i++){
            cnt[pr[i].s]++;
            if(pr[i].f==pr[i+1].f)
                continue;
            ll tim=(ll)cnt[0]*a+(ll)cnt[1]*b;
            if(tim>pr[i+1].f-1)
                continue;
            //printf("%i: %lld %i\n",i,tim,pr[i+1].f-1);
            int cntExtra=0;
            int mali=total[0]-cnt[0],veliki=total[1]-cnt[1];
            int ostalo=min((ll)mali,(pr[i+1].f-1-tim)/a);
            cntExtra+=ostalo;
            tim+=ostalo*a;
            ostalo=min((ll)veliki,(pr[i+1].f-1-tim)/b);
            cntExtra+=ostalo;
            tim+=ostalo*b;
            if(tim<=pr[i+1].f-1)
                sol=max(sol,i+1+cntExtra);
        }
        printf("%i\n",sol);
	}
    return 0;
}