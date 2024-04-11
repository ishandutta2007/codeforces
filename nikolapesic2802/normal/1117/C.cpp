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
	int x1,y1,x2,y2;
	scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
	if(x1==x2&&y1==y2)
    {
        printf("0\n");
        return 0;
    }
	int n;
	scanf("%i",&n);
	string s;
	cin >> s;
	s=s+s;
	vector<pair<int,int> > o(n);
	for(int i=0;i<n;i++)
    {
        if(i)
            o[i]=o[i-1];
        if(s[i]=='U')
            o[i].s++;
        if(s[i]=='D')
            o[i].s--;
        if(s[i]=='L')
            o[i].f--;
        if(s[i]=='R')
            o[i].f++;
    }
    for(int i=0;i<n;i++)
    {
        ll xx=x1+(ll)o[i].f;
        ll yy=y1+(ll)o[i].s;
        ll dist=abs((ll)x2-xx)+abs((ll)y2-yy);
        if(dist<=i+1)
        {
            printf("%i\n",i+1);
            return 0;
        }
    }
    ll lim=2e9+100;
    ll l=0,r=lim;
    while(l<r)
    {
        ll m=(l+r+1)>>1;
        ll xx=x1+(ll)m*o[n-1].f;
        ll yy=y1+(ll)m*o[n-1].s;
        ll dist=abs((ll)x2-xx)+abs((ll)y2-yy);
        if(dist<=(ll)m*n)
        {
            r=m-1;
        }
        else
        {
            l=m;
        }
    }
    if(l==lim)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        ll xx=x1+l*(ll)o[n-1].f+o[i].f;
        ll yy=y1+l*(ll)o[n-1].s+o[i].s;
        ll dist=abs((ll)x2-xx)+abs((ll)y2-yy);
        if(dist<=i+1+(ll)l*n)
        {
            printf("%lld\n",i+1+(ll)l*n);
            return 0;
        }
    }
    assert(0);
    return 0;
}