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

const int N=2e5+5;
int dp[N][3],oo=INT_MAX/4;
int n,a,b;
vector<vector<int> > graf(N);
int calc(int tr,int par,int d){
    if(dp[tr][d]!=-1)
        return dp[tr][d];
    dp[tr][d]=-oo;
    vector<int> susedi;
    for(auto p:graf[tr])
        if(p!=par)
            susedi.pb(p);
    if(susedi.empty()){
        if(d>1)
            return dp[tr][d]=-oo;
        return dp[tr][d]=0;
    }
    if(susedi.size()==1){
        if(d==1)
            return dp[tr][d]=1+calc(susedi[0],tr,d);
        if(d==2)
            return dp[tr][d]=max(1+calc(susedi[0],tr,d),1+calc(susedi[0],tr,d-1));
        if(d==3)
            return dp[tr][d]=max(calc(susedi[0],tr,d),1+calc(susedi[0],tr,d-1));
    }
    multiset<int,greater<int> > jed;
    int n=susedi.size();
    for(int i=0;i<n;i++)
        jed.insert(calc(susedi[i],tr,1));
    if(d==1){
        return dp[tr][d]=1+*jed.begin();
    }
    if(d==2){
        auto it=jed.begin();
        it++;
        dp[tr][d]=max(1+*jed.begin(),2+*jed.begin()+*it);
        for(int i=0;i<n;i++)
            dp[tr][d]=max(dp[tr][d],1+calc(susedi[i],tr,2));
        return dp[tr][d];
    }
    for(int i=0;i<n;i++)
        dp[tr][d]=max({dp[tr][d],calc(susedi[i],tr,3),1+calc(susedi[i],tr,2)});
    auto it=jed.begin();
    it++;
    dp[tr][d]=max(dp[tr][d],2+*jed.begin()+*it);
    if(jed.size()>2){
        auto it2=it;
        it2++;
        dp[tr][d]=max(dp[tr][d],3+*jed.begin()+*it+*it2);
    }
    for(int i=0;i<n;i++){
        jed.erase(jed.find(calc(susedi[i],tr,1)));
        dp[tr][d]=max(dp[tr][d],2+*jed.begin()+calc(susedi[i],tr,2));
        jed.insert(calc(susedi[i],tr,1));
    }
    return dp[tr][d];
}

vector<int> fuck(int tr,int par,int d){
    vector<int> susedi;
    for(auto p:graf[tr])
        if(p!=par)
            susedi.pb(p);
    if(susedi.empty()){
        return {tr};
    }
    if(susedi.size()==1){
        if(d==1)
            return fuck(susedi[0],tr,d);
        if(d==2){
            if(1+calc(susedi[0],tr,d)>1+calc(susedi[0],tr,d-1))
                return fuck(susedi[0],tr,d);
            vector<int> t=fuck(susedi[0],tr,d-1);
            t.pb(tr);
            return t;
        }
        if(calc(susedi[0],tr,d)>1+calc(susedi[0],tr,d-1))
            return fuck(susedi[0],tr,d);
        vector<int> t=fuck(susedi[0],tr,d-1);
        t.pb(tr);
        return t;
    }
    multiset<pair<int,int>,greater<pair<int,int> > > jed;
    int n=susedi.size();
    for(int i=0;i<n;i++)
        jed.insert({calc(susedi[i],tr,1),susedi[i]});
    if(d==1)
        return fuck((*jed.begin()).s,tr,1);
    if(d==2){
        auto it=jed.begin();
        it++;
        if(dp[tr][d]==1+(*jed.begin()).f){
            vector<int> t=fuck((*jed.begin()).s,tr,1);
            t.pb(tr);
            return t;
        }
        if(dp[tr][d]==2+(*jed.begin()).f+(*it).f){
            vector<int> t=fuck((*jed.begin()).s,tr,1),p=fuck((*it).s,tr,1);
            t.pb(p[0]);
            return t;
        }
        for(int i=0;i<n;i++){
            if(dp[tr][d]==1+calc(susedi[i],tr,2))
                return fuck(susedi[i],tr,2);
        }
        assert(0);
    }
    for(int i=0;i<n;i++){
        if(dp[tr][d]==calc(susedi[i],tr,3))
            return fuck(susedi[i],tr,3);
        if(dp[tr][d]==1+calc(susedi[i],tr,2)){
            vector<int> t=fuck(susedi[i],tr,2);
            t.pb(tr);
            return t;
        }
    }
    auto it=jed.begin();
    it++;
    if(dp[tr][d]==2+(*jed.begin()).f+(*it).f){
        vector<int> t=fuck((*jed.begin()).s,tr,1),p=fuck((*it).s,tr,1);
        t.pb(p[0]);
        t.pb(tr);
        return t;
    }
    if(jed.size()>2){
        auto it2=it;
        it2++;
        if(dp[tr][d]==3+(*jed.begin()).f+(*it).f+(*it2).f){
            vector<int> t=fuck((*jed.begin()).s,tr,1),p=fuck((*it).s,tr,1),o=fuck((*it2).s,tr,1);
            t.pb(p[0]);
            t.pb(o[0]);
            return t;
        }
    }
    for(int i=0;i<n;i++){
        jed.erase(jed.find({calc(susedi[i],tr,1),susedi[i]}));
        if(dp[tr][d]==2+(*jed.begin()).f+calc(susedi[i],tr,2)){
            vector<int> t=fuck((*jed.begin()).s,tr,1),d=fuck(susedi[i],tr,2);
            d.pb(t[0]);
            return d;
        }
        jed.insert({calc(susedi[i],tr,1),susedi[i]});
    }
    assert(0);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	scanf("%i",&n);
	for(int i=1;i<n;i++)
        scanf("%i %i",&a,&b),graf[a-1].pb(b-1),graf[b-1].pb(a-1);
    printf("%i\n",calc(0,0,3));
    vector<int> a=fuck(0,0,3);
    for(auto p:a)
        printf("%i ",p+1);
    return 0;
}