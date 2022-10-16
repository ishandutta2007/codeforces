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

const int N=5001;
struct num{
    vector<pair<int,int> > factors;
}aa;
vector<pair<int,int> > em;
vector<vector<pair<num,int> > > grupe(1);
vector<ll> costGrupe(1);
vector<int> groupSiz(1);
vector<pair<num,int> > a;
int total=0;
vector<int> cnt(N),di(N);
vector<int> cntFact(N);
num lca;
int dist(num a,num b){
    //cout << a.factors << b.factors << endl;
    int cnt=0;
    int n=min(a.factors.size(),b.factors.size());
    vector<bool> isti(n);
    for(int i=0;i<n;i++){
        if(i==0)
            isti[i]=1;
        else
            isti[i]=isti[i-1];
        isti[i]=isti[i]&&a.factors[i]==b.factors[i];
    }
    while(true){
        if(a.factors.empty()){
            for(auto p:b.factors)
                cnt+=p.s;
            lca=aa;
            return cnt;
        }
        if(b.factors.empty()){
            for(auto p:a.factors)
                cnt+=p.s;
            lca=aa;
            return cnt;
        }
        if(a.factors.back().f==b.factors.back().f){
            int mn=min(a.factors.back().s,b.factors.back().s);
            cnt+=a.factors.back().s-mn+b.factors.back().s-mn;
            int koji=a.factors.back().f;
            a.factors.pop_back();
            b.factors.pop_back();
            if(a.factors.size()==b.factors.size()&&(a.factors.empty()||isti[a.factors.size()-1])){
                a.factors.pb({koji,mn});
                lca=a;
                return cnt;
            }
            cnt+=2*mn;
            continue;
        }
        if(a.factors.back().f<b.factors.back().f){
            cnt+=a.factors.back().s;
            a.factors.pop_back();
            continue;
        }
        cnt+=b.factors.back().s;
        b.factors.pop_back();
        continue;
    }
    //printf("%i!\n",sol);
    assert(0);
    return cnt;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%i",&a);
        if(a==0)
            a++;
        cnt[a]++;
    }
    di[1]=1;
    for(int i=2;i<N;i++)
        if(!di[i])
            for(int j=i;j<N;j+=i)
                if(!di[j])
                    di[j]=i;
    grupe.back().pb({aa,cnt[1]});
    groupSiz.back()=cnt[1];
    ll minSol=LLONG_MAX;
    ll totalcost=0;
    num last=aa;
    for(int i=2;i<N;i++){
        int tr=i;
        while(tr>1)
            cntFact[di[tr]]++,total++,tr/=di[tr];
        if(di[i]==i)
            grupe.pb(a),costGrupe.pb(0),groupSiz.pb(0);
        costGrupe.back()+=(ll)total*cnt[i];
        totalcost+=(ll)total*cnt[i];
        num a;
        for(int j=N-1;j>=2;j--)
            if(cntFact[j]!=0)
                a.factors.pb({j,cntFact[j]});
        grupe.back().pb({a,cnt[i]});
        groupSiz.back()+=cnt[i];
        dist(a,last);
        if(lca.factors.size())
            grupe.back().pb({lca,0});
        last=a;
        //cout << a.factors << endl;
    }
    int mxSiz=0;
    for(auto p:grupe)
        mxSiz=max(mxSiz,(int)p.size());
    int k=grupe.size();
    for(int i=0;i<k;i++){
        //printf("%i!\n",i);
        for(auto p:grupe[i]){
            ll trcost=0;
            trcost+=(ll)(n-groupSiz[i])*dist(p.f,aa);
            trcost+=totalcost-costGrupe[i];
            for(auto d:grupe[i])
                trcost+=(ll)d.s*dist(d.f,p.f);
            minSol=min(minSol,trcost);
        }
    }
    printf("%lld\n",minSol);
    return 0;
}