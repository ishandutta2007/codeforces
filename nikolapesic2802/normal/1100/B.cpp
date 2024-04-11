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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int N;
struct segTree{
    vector<int> minn;
    vector<int> lazy;
    void init()
    {
        minn.resize(4*N);
        lazy.resize(4*N);
    }
    void prop(int i)
    {
        lazy[2*i]+=lazy[i];
        minn[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        minn[2*i+1]+=lazy[i];
        lazy[i]=0;
    }
    void update(int i)
    {
        minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    void inc(int pos,int l=0,int r=N-1,int i=1)
    {
        if(l>pos||r<pos)
            return;
        if(l==r&&l==pos)
        {
            minn[i]++;
            return;
        }
        int m=(l+r)>>1;
        prop(i);
        inc(pos,l,m,2*i);
        inc(pos,m+1,r,2*i+1);
        update(i);
    }
}st;
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	N=n;
	st.init();
	string sol;
	for(int i=0;i<m;i++)
    {
        int a;
        scanf("%i",&a);
        st.inc(a-1);
        if(st.minn[1]>0)
        {
            sol+='1';
            st.lazy[1]--;
            st.minn[1]--;
        }
        else
        {
            sol+='0';
        }
    }
    cout << sol << endl;
    return 0;
}