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
vector<int> dep(N);
struct segTree{
    vector<int> mL,mR,mA,mLA,mAR,mLAR,lazy;
    void update(int i)
    {
        mL[i]=max(mL[2*i],mL[2*i+1]);
        mR[i]=max(mR[2*i],mR[2*i+1]);
        mA[i]=max(mA[2*i],mA[2*i+1]);
        mLA[i]=max(mLA[2*i],mLA[2*i+1]);
        mAR[i]=max(mAR[2*i],mAR[2*i+1]);
        mLAR[i]=max(mLAR[2*i],mLAR[2*i+1]);
        mLA[i]=max(mLA[i],mL[2*i]+mA[2*i+1]);
        mAR[i]=max(mAR[i],mA[2*i]+mR[2*i+1]);
        mLAR[i]=max({mLAR[i],mLA[2*i]+mR[2*i+1],mL[2*i]+mAR[2*i+1]});
    }
    void prop(int i)
    {
        mL[2*i]+=lazy[i];
        mR[2*i]+=lazy[i];
        mA[2*i]-=2*lazy[i];
        mLA[2*i]-=lazy[i];
        mAR[2*i]-=lazy[i];
        lazy[2*i]+=lazy[i];
        mL[2*i+1]+=lazy[i];
        mR[2*i+1]+=lazy[i];
        mA[2*i+1]-=2*lazy[i];
        mLA[2*i+1]-=lazy[i];
        mAR[2*i+1]-=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
    }
    void build(int l,int r,int i)
    {
        if(l==r)
        {
            mL[i]=mR[i]=dep[l];
            mA[i]=-2*dep[l];
            mLA[i]=mAR[i]=-dep[l];
            mLAR[i]=0;
            return;
        }
        int m=(l+r)>>1;
        build(l,m,2*i);
        build(m+1,r,2*i+1);
        update(i);
    }
    void init()
    {
        mL.resize(4*N);
        mR.resize(4*N);
        mA.resize(4*N);
        mLA.resize(4*N);
        mAR.resize(4*N);
        mLAR.resize(4*N);
        lazy.resize(4*N);
        build(0,N-1,1);
    }
    void add(int qs,int qe,int k,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            mL[i]+=k;
            mR[i]+=k;
            mA[i]-=2*k;
            mLA[i]-=k;
            mAR[i]-=k;
            lazy[i]+=k;
            return;
        }
        prop(i);
        int m=(l+r)>>1;
        add(qs,qe,k,l,m,2*i);
        add(qs,qe,k,m+1,r,2*i+1);
        update(i);
    }
}st;
int main()
{
	int n,q;
	scanf("%i %i",&n,&q);
	n=2*(n-1);
	string s;
	cin >> s;
	dep[0]=1;
	for(int i=1;i<n;i++)
        if(s[i]=='(')
            dep[i]=dep[i-1]+1;
        else
            dep[i]=dep[i-1]-1;
    st.init();
    printf("%i\n",st.mLAR[1]);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        if(a>b)
            swap(a,b);
        a--;b-=2;
        if(s[a]=='(')
            st.add(a,b,-2);
        else
            st.add(a,b,2);
        swap(s[a],s[b+1]);
        printf("%i\n",st.mLAR[1]);
    }
    return 0;
}