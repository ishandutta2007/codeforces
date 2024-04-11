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
	string l,r;
	cin >> l >> r;
	vector<vector<int> > cnt(100);
	vector<pair<int,int> > pairs;
	for(int i=0;i<n;i++)
        cnt[l[i]-'?'].pb(i);
    vector<int> upitnici;
    for(int i=0;i<n;i++)
    {
        char p=r[i];
        if(p=='?')
        {
            upitnici.pb(i);
        }
        else
        {
            if(cnt[p-'?'].size())
            {
                pairs.pb({cnt[p-'?'].back(),i});
                cnt[p-'?'].pop_back();
            }
            else
            {
                if(cnt[0].size())
                {
                    pairs.pb({cnt[0].back(),i});
                    cnt[0].pop_back();
                }
            }
        }
    }
    for(auto p:cnt)
        for(auto d:p)
            if(upitnici.size())
            {
                pairs.pb({d,upitnici.back()});
                upitnici.pop_back();
            }
    printf("%i\n",pairs.size());
    for(auto p:pairs)
        printf("%i %i\n",p.f+1,p.s+1);
    return 0;
}