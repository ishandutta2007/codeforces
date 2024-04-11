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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> v(255);
	v['a']=1;
	v['e']=1;
	v['i']=1;
	v['o']=1;
	v['u']=1;
	const int N=1e6+1;
	vector<vector<pair<int,int> > > num(N);
	vector<string> s(n);
	for(int i=0;i<n;i++)
    {
        cin >> s[i];
        int cnt=0;
        int last;
        for(auto p:s[i])
            if(v[p]==1)
                cnt++,last=p;
        num[cnt].pb({last,i});
    }
    vector<pair<int,int> > prvi,drugi;
    for(int i=0;i<N;i++)
    {
        sort(all(num[i]));
        vector<vector<int> > nums;
        if(num[i].size())
            nums.pb({num[i][0].s});
        for(int j=1,n=num[i].size();j<n;j++)
        {
            if(num[i][j].f==num[i][j-1].f)
                nums.back().pb(num[i][j].s);
            else
                nums.pb({num[i][j].s});
        }
        vector<int> odd;
        for(auto p:nums)
        {
            while(p.size()>=2)
            {
                pair<int,int> tr;
                tr.f=p.back();
                p.pop_back();
                tr.s=p.back();
                p.pop_back();
                drugi.pb(tr);
            }
            if(p.size())
                odd.pb(p.back());
        }
        while(odd.size()>=2)
        {
            pair<int,int> tr;
            tr.f=odd.back();
            odd.pop_back();
            tr.s=odd.back();
            odd.pop_back();
            prvi.pb(tr);
        }
    }
    while(drugi.size()>prvi.size())
        prvi.pb(drugi.back()),drugi.pop_back();
    cout << min(drugi.size(),prvi.size()) << endl;
    int i=0,j=0;
    while(i<prvi.size()&&j<drugi.size())
    {
        cout << s[prvi[i].f] << " " << s[drugi[i].f] << endl << s[prvi[i].s] << " " << s[drugi[i].s] << endl;
        i++;
        j++;
    }
    return 0;
}