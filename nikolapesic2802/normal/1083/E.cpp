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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
struct func{
    int x;
    ll p;
};
func null={-1,0};
ll calc(func f,int y)
{
    return (ll)f.p-(ll)f.x*y;
}
struct Node{
    int l,r;
    Node* left;
    Node* right;
    func f;
    Node(){
        left=NULL;
        right=NULL;
        f=null;
    }
    void extend()
    {
        if(left==NULL)
        {
            int m=(l+r)>>1;
            left=new Node();
            right=new Node();
            left->l=l;
            left->r=m;
            right->l=m;
            right->r=r;
        }
    }
    void add(func ne)
    {
        if(f.x==-1){
            f=ne;
            return;
        }
        int m=(l+r)>>1;
        bool mid=calc(f,m)<calc(ne,m);
        bool lft=calc(f,l)<calc(ne,l);
        if(mid)
            swap(f,ne);
        if(r-l==1)
            return;
        extend();
        if(mid!=lft)
            left->add(ne);
        else
            right->add(ne);
    }
    ll get(int y)
    {
        if(f.x==-1)
            return 0;
        int m=(l+r)>>1;
        if(r-l==1)
            return calc(f,y);
        extend();
        if(y<m)
            return max(calc(f,y),left->get(y));
        return max(calc(f,y),right->get(y));
    }
};
int main()
{
	int n;
	scanf("%i",&n);
	vector<pair<pair<int,int>,ll> > r;
	vector<pair<long double,int> > order;
	for(int i=0;i<n;i++)
    {
        int x,y;
        ll a;
        scanf("%i %i %lld",&x,&y,&a);
        r.pb({{x,y},a});
    }
    sort(all(r));
    Node LiChao;
    ll maxx=0;
    LiChao.l=1;
    LiChao.r=1e9+5;
    func f={0,0};
    LiChao.f=f;
    for(auto p:r)
    {
        int x=p.first.first;
        int y=p.first.second;
        ll c=p.second;
        ll a=LiChao.get(y)-c+(ll)x*y;
        //printf("%i %i %lld: %lld\n",x,y,c,a);
        maxx=max(maxx,a);
        func t={x,a};
        LiChao.add(t);
    }
    printf("%lld\n",maxx);
    return 0;
}