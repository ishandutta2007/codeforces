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
	int n;
	scanf("%i",&n);
	vector<int> niz(n);
	vector<int> maxbit(n);
	int m=0;
	for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        for(int j=0;j<31;j++)
            if(niz[i]&(1<<j))
                maxbit[i]=j;
        m=max(m,maxbit[i]);
    }
    while(true)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
            if(m==maxbit[i])
                cnt++;
        if(cnt==n)
        {
            int sub=m;
            m=-1;
            for(int i=0;i<n;i++)
            {
                maxbit[i]=-1;
                niz[i]-=(1<<sub);
                for(int j=0;j<31;j++)
                if(niz[i]&(1<<j))
                    maxbit[i]=j;
                 m=max(m,maxbit[i]);
            }
        }
        else
            break;
        if(m==-1)
        {
            printf("0\n");
            return 0;
        }
    }
    int sol=0;
    for(int i=0;i<n;i++)
    {
        if(m==maxbit[i])
        {
            int tr=i-1;
            int ma=0;
            while(tr>=0&&maxbit[tr]<m)
            {
                ma=max(ma,niz[tr]);
                sol=max(sol,niz[i]^ma);
                tr--;
            }
            if(tr>=0)
            {
                ma=max(ma,niz[tr]);
                sol=max(sol,niz[i]^ma);
            }
            tr=i+1;
            ma=0;
            while(tr<n&&maxbit[tr]<m)
            {
                ma=max(ma,niz[tr]);
                sol=max(sol,niz[i]^ma);
                tr++;
            }
            if(tr<n)
            {
                ma=max(ma,niz[tr]);
                sol=max(sol,niz[i]^ma);
            }
        }
    }
    printf("%i\n",sol);
    return 0;
}