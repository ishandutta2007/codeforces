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

const int N=4e5+5;
vector<int> mn(4*N);
void add(int pos,int l=0,int r=N-1,int i=1){
    if(l==r){
        mn[i]++;
        return;
    }
    int m=(l+r)>>1;
    if(pos<=m)
        add(pos,l,m,2*i);
    else
        add(pos,m+1,r,2*i+1);
    mn[i]=min(mn[2*i],mn[2*i+1]);
}
int getMn(int qs,int qe,int l=0,int r=N-1,int i=1){
    if(qs>r||qe<l)
        return INT_MAX;
    if(qs<=l&&qe>=r)
        return mn[i];
    int m=(l+r)>>1;
    return min(getMn(qs,qe,l,m,2*i),getMn(qs,qe,m+1,r,2*i+1));
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int q,x;
	scanf("%i %i",&q,&x);
	while(q--){
        int y;
        scanf("%i",&y);
        add(y%x);
        int l=0,r=N-1;
        while(l<r){
            int m=(l+r+1)>>1;
            int a=m/x,b=m%x;
            bool moze=getMn(0,x-1)>=a&&getMn(0,b-1)>a;
            if(moze)
                l=m;
            else
                r=m-1;
        }
        printf("%i\n",l);
	}
    return 0;
}