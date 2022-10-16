
// Problem : C. World of Darkraft: Battle for Azathoth
// Contest : Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : http://codeforces.com/contest/1320/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

struct segTree{
    private:
    int n;
    vector<int> mx,mn,lazySet;
    vector<long long> sum,lazyAdd;

    void update(int i){
        mx[i]=max(mx[2*i],mx[2*i+1]);
        mn[i]=min(mn[2*i],mn[2*i+1]);
        sum[i]=sum[2*i]+sum[2*i+1];
    }
    void init(int l,int r,int i,vector<int> &vals){
        if(l==r){
            mn[i]=mx[i]=sum[i]=vals[l];
            return;
        }
        int m=(l+r)/2;
        init(l,m,2*i,vals);
        init(m+1,r,2*i+1,vals);
        update(i);
    }
    void prop(int i,int l,int m,int r){
        if(lazySet[i]!=INT_MAX){
            mx[2*i]=mx[2*i+1]=mn[2*i]=mn[2*i+1]=lazySet[2*i]=lazySet[2*i+1]=lazySet[i];
            sum[2*i]=(long long)(m-l+1)*lazySet[i];
            sum[2*i+1]=(long long)(r-m)*lazySet[i];
            lazyAdd[2*i]=0;
            lazyAdd[2*i+1]=0;
            lazySet[i]=INT_MAX;
        }
        if(lazyAdd[i]){
            mx[2*i]+=lazyAdd[i];
            mx[2*i+1]+=lazyAdd[i];
            mn[2*i]+=lazyAdd[i];
            mn[2*i+1]+=lazyAdd[i];
            sum[2*i]+=(long long)(m-l+1)*lazyAdd[i];
            sum[2*i+1]+=(long long)(r-m)*lazyAdd[i];
            lazyAdd[2*i]+=lazyAdd[i];
            lazyAdd[2*i+1]+=lazyAdd[i];
            lazyAdd[i]=0;
        }
    }
    void setSingle(int pos,int x,int l,int r,int i){
        if(l==r){
            mx[i]=x;
            mn[i]=x;
            sum[i]=x;
            return;
        }
        int m=(l+r)/2;
        prop(i,l,m,r);
        if(pos<=m)
            setSingle(pos,x,l,m,2*i);
        else
            setSingle(pos,x,m+1,r,2*i+1);
        update(i);
    }
    void addSingle(int pos,int x,int l,int r,int i){
        if(l==r){
            mx[i]+=x;
            mn[i]+=x;
            sum[i]+=x;
            return;
        }
        int m=(l+r)/2;
        prop(i,l,m,r);
        if(pos<=m)
            addSingle(pos,x,l,m,2*i);
        else
            addSingle(pos,x,m+1,r,2*i+1);
        update(i);
    }
    void setRange(int qs,int qe,int x,int l,int r,int i){
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r){
            lazyAdd[i]=0;
            mx[i]=mn[i]=lazySet[i]=x;
            sum[i]=(long long)(r-l+1)*x;
            return;
        }
        int m=(l+r)/2;
        prop(i,l,m,r);
        setRange(qs,qe,x,l,m,2*i);
        setRange(qs,qe,x,m+1,r,2*i+1);
        update(i);
    }
    void addRange(int qs,int qe,int x,int l,int r,int i){
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r){
            lazyAdd[i]+=x;
            mx[i]+=x;
            mn[i]+=x;
            sum[i]+=(long long)(r-l+1)*x;
            return;
        }
        int m=(l+r)/2;
        prop(i,l,m,r);
        addRange(qs,qe,x,l,m,2*i);
        addRange(qs,qe,x,m+1,r,2*i+1);
        update(i);
    }
    int getMx(int qs,int qe,int l,int r,int i){
        if(qs>r||qe<l)
            return INT_MIN;
        if(qs<=l&&qe>=r)
            return mx[i];
        int m=(l+r)/2;
        prop(i,l,m,r);
        return max(getMx(qs,qe,l,m,2*i),getMx(qs,qe,m+1,r,2*i+1));
    }
    int getMn(int qs,int qe,int l,int r,int i){
        if(qs>r||qe<l)
            return INT_MAX;
        if(qs<=l&&qe>=r)
            return mn[i];
        int m=(l+r)/2;
        prop(i,l,m,r);
        return min(getMn(qs,qe,l,m,2*i),getMn(qs,qe,m+1,r,2*i+1));
    }
    long long getSum(int qs,int qe,int l,int r,int i){
        if(qs>r||qe<l)
            return 0;
        if(qs<=l&&qe>=r)
            return sum[i];
        int m=(l+r)/2;
        prop(i,l,m,r);
        return getSum(qs,qe,l,m,2*i)+getSum(qs,qe,m+1,r,2*i+1);
    }

    public:
    void init(int N){ //Make a tree of size N and set it to zeros
        n=N;
        int pwr=1;
        while(pwr<2*n)
            pwr*=2;
        mx.resize(pwr);
        mn.resize(pwr);
        sum.resize(pwr);
        lazyAdd.resize(pwr);
        lazySet.resize(pwr);
        for(int i=0;i<pwr;i++)
            mx[i]=mn[i]=sum[i]=lazyAdd[i]=0,lazySet[i]=INT_MAX;
    }
    void init(vector<int> &vals){ //Make a tree with the given vals
        init(vals.size());
        init(0,n-1,1,vals);
    }
    void singleSet(int pos,int x){setSingle(pos,x,0,n-1,1);}
    void singleAdd(int pos,int x){addSingle(pos,x,0,n-1,1);}
    void rangeSet(int qs,int qe,int x){setRange(qs,qe,x,0,n-1,1);}
    void rangeAdd(int qs,int qe,int x){addRange(qs,qe,x,0,n-1,1);}
    int getMax(int qs,int qe){return getMx(qs,qe,0,n-1,1);}
    int getMin(int qs,int qe){return getMn(qs,qe,0,n-1,1);}
    long long getSum(int qs,int qe){return getSum(qs,qe,0,n-1,1);}
}drvo;


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,p;
	scanf("%i %i %i",&n,&m,&p);
	vector<pair<int,int>> a(n),b(m);
	for(int i=0;i<n;i++)
		scanf("%i %i",&a[i].f,&a[i].s);
	for(int i=0;i<m;i++)
		scanf("%i %i",&b[i].f,&b[i].s);
	sort(all(a));
	sort(all(b));
	vector<int> costs;
	for(int i=0;i<m;i++)
		costs.pb(-b[i].s);
	drvo.init(costs);
	vector<pair<pair<int,int>,int> > mon(p);
	for(int i=0;i<p;i++)
		scanf("%i %i %i",&mon[i].f.f,&mon[i].f.s,&mon[i].s);
	sort(all(mon));
	int sol=INT_MIN;
	int tr=0;
	for(int i=0;i<n;i++){
		while(tr<p&&mon[tr].f.f<a[i].f){
			auto it=lower_bound(all(b),make_pair(mon[tr].f.s,INT_MAX));
			if(it==b.end()){
				tr++;
				continue;
			}
			int indeks=it-b.begin();
			drvo.rangeAdd(indeks,(int)b.size()-1,mon[tr].s);
			tr++;
		}
		int mx=drvo.getMax(0,b.size()-1)-a[i].s;
		sol=max(sol,mx);
	}
	printf("%i\n",sol);
	return 0;
}