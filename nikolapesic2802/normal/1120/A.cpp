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
	int m,k,n,s;
	scanf("%i %i %i %i",&m,&k,&n,&s);
	vector<int> niz(m);
	for(int i=0;i<m;i++)
        scanf("%i",&niz[i]);
    int l=0,r=0;
    int cnt=0;
    vector<int> need(5e5+5);
    vector<int> types(5e5+5);
    for(int i=0;i<s;i++)
    {
        int a;
        scanf("%i",&a);
        if(types[a]==0)
            cnt++;
        types[a]++;
        need[a]++;
    }
    while(r<m)
    {
        while(cnt>0&&r<m)
        {
            int a=niz[r];
            if(types[a]==1)
                cnt--;
            types[a]--;
            r++;
        }
        while(cnt==0&&l<m)
        {
            int pre=l/k;
            int posle=(m-r)/k;
            if(pre+posle>=n-1)
            {
                //printf("%i %i\n",l,r);
                while(r-l<k)
                    r++;
                if(r>m)
                {
                    printf("-1\n");
                    return 0;
                }
                int rem=r-l;
                vector<int> remove;
                for(int i=l;i<r;i++)
                {
                    if(need[niz[i]]<=0)
                    {
                        if(rem>k)
                            remove.pb(i+1),rem--;
                    }
                    else
                        need[niz[i]]--;
                }
                //assert(rem==k);
                while(l>0&&l/k+(m-r)/k>=n)
                {
                    remove.pb(l);
                    l--;
                }
                while(r<m&&l/k+(m-r)/k>=n)
                {
                    remove.pb(r+1);
                    r++;
                }
                assert(l/k+(m-r)/k==n-1);
                while(l%k!=0)
                {
                    remove.pb(l);
                    l--;
                }
                while((m-r)%k!=0)
                {
                    remove.pb(r+1);
                    r++;
                }
                //assert(remove.size()==m-n*k);
                printf("%i\n",remove.size());
                for(auto p:remove)
                    printf("%i ",p);
                return 0;
            }
            int a=niz[l];
            if(types[a]==0)
                cnt++;
            types[a]++;
            l++;
        }
    }
    printf("-1\n");
    return 0;
}