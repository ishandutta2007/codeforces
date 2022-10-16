
// Problem : E. Divide Square
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/E
// Memory Limit : 384 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

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
	drvo.init(1000001);
	int n,m;
	rd(n,m);
	vector<pair<int,pair<int,int> > > events;
	ll cnt=1;
	for(int i=0;i<n;i++){
		int x,l,r;
		rd(x,l,r);
		if(l==0&&r==1000000)
			cnt++;
		events.pb({l,{-1,x}});
		events.pb({r+1,{-2,x}});
	}
	for(int i=0;i<m;i++){
		int x,l,r;
		rd(x,l,r);
		if(l==0&&r==1000000)
			cnt++;
		events.pb({x,{l,r}});
	}
	sort(all(events));
	for(auto p:events){
		if(p.s.f==-1){
			drvo.singleAdd(p.s.s,1);
		}
		else{
			if(p.s.f==-2){
				drvo.singleAdd(p.s.s,-1);
			}
			else{
				cnt+=drvo.getSum(p.s.f,p.s.s);
			}
		}
	}
	printf("%lld\n",cnt);
	return 0;
}