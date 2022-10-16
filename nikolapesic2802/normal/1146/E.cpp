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

const int N=2e5+5,offset=1e5+1;
vector<int> arr;
struct segTree{
    vector<int> f,p,postavljen;
    void init()
    {
        f.resize(4*N);
        p.resize(4*N);
        postavljen.resize(4*N);
    }
    void prop(int i)
    {
        if(postavljen[i])
        {
            f[2*i]=0;
            f[2*i+1]=0;
            p[2*i]=p[i];
            p[2*i+1]=p[i];
            postavljen[2*i]=1;
            postavljen[2*i+1]=1;
            postavljen[i]=0;
        }
        f[2*i]^=f[i];
        f[2*i+1]^=f[i];
        f[i]=0;
    }
    void flipuj(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>qe)
            return;
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            f[i]^=1;
            return;
        }
        prop(i);
        int m=(l+r)>>1;
        flipuj(qs,qe,l,m,2*i);
        flipuj(qs,qe,m+1,r,2*i+1);
    }
    void postavi(int qs,int qe,int val,int l=0,int r=N-1,int i=1)
    {
        if(qs>qe)
            return;
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {

            p[i]=val;
            f[i]=0;
            postavljen[i]=1;
            return;
        }
        prop(i);
        int m=(l+r)>>1;
        postavi(qs,qe,val,l,m,2*i);
        postavi(qs,qe,val,m+1,r,2*i+1);
    }
    int get(int pos,int l=0,int r=N-1,int i=1)
    {
        if(l>pos||r<pos)
            return 0;
        if(l==pos&&r==pos){
            return p[i]^f[i];
        }
        prop(i);
        int m=(l+r)>>1;
        return get(pos,l,m,2*i)+get(pos,m+1,r,2*i+1);
    }
}st;
int main()
{
	int n,q;
	scanf("%i %i",&n,&q);
	arr.resize(n);
	for(int i=0;i<n;i++)
        scanf("%i",&arr[i]),arr[i]+=offset;
    st.init();
    for(int i=0;i<q;i++)
    {
        string c;
        cin >> c;
        int p;
        scanf("%i",&p);
        if(c[0]=='>')
        {
            int poz=abs(p);
            int neg=poz*-1;
            if(p<0)
            {
                st.flipuj(neg+offset+1,poz+offset-1);
                st.postavi(0,neg+offset,0);
                st.postavi(poz+offset,N-1,1);
            }
            else
            {
                st.postavi(0,neg-1+offset,0);
                st.postavi(poz+1+offset,N-1,1);
            }
        }
        else
        {
            int poz=abs(p);
            int neg=poz*-1;
            if(p>0)
            {
                st.postavi(poz+offset,N-1,0);
                st.postavi(0,neg+offset,1);
                st.flipuj(neg+offset+1,poz+offset-1);
            }
            else
            {
                st.postavi(0,neg-1+offset,1);
                st.postavi(poz+1+offset,N-1,0);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(st.get(arr[i]))
            printf("%i ",-1*(arr[i]-offset));
        else
            printf("%i ",arr[i]-offset);
    }
    return 0;
}