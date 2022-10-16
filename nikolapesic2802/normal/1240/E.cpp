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

const int N=5e5+1;
int main()
{
    int n,a;
    scanf("%i",&n);
    vector<int> cnt(N),nxt(N),sums(N);
    for(int i=0;i<n;i++)
        cin >> a,cnt[a]++,sums[a]++;
    int sl=-1;
    for(int i=0;i<N;i++){
    	nxt[i]=sl;
    	if(cnt[i])
    		sl=i;
    	if(i)
    		sums[i]+=sums[i-1];
    }
    ll sol=0;
    for(int y=2;y<N;y++)
    {
    	ll imam=0,last=0;
    	vector<int> stapovi;
    	for(int i=y-1;;i=min(i+y,N-1))
    	{
    		int tr=i;
    		for(int j=0;j<2&&tr>i-y;)
    		{
    			if(cnt[tr]>=2&&j==0)
    				stapovi.pb(tr),stapovi.pb(tr),j+=2;
    			if(cnt[tr]>=1&&j<2)
    				stapovi.pb(tr),j++;
    			tr=nxt[tr];
    		}
    		imam+=(ll)i/(ll)y*(ll)(sums[i]-last);
    		last=sums[i];
    		if(i==N-1)
                break;
    	}
    	sort(stapovi.rbegin(),stapovi.rend());
    	int l=2,r=N-1,ans=0;
    	while(l<=r)
    	{
    		int x=(l+r)>>1,min2=INT_MAX/2,min11=INT_MAX/2,min12=INT_MAX/2;
            for(auto p:stapovi)
            {
                if(p>=x)
                {
                    int val=p/y-(p-x)/y;
                    if(val<min11)
                        min12=min11,min11=val;
                    else
                        if(val<min12)
                            min12=val;
                }
                else
                    break;
                if(p>=2*x)
                    min2=min(min2,p/y-(p-2*x)/y);
            }
    		if(imam-min(min2,min11+min12)>=x)
    			l=x+1,ans=x;
    		else
    			r=x-1;
    	}

    	sol=max(sol,(ll)y*ans);
    }
    printf("%lld\n",sol);
    return 0;
}