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
	int n,i,a;
	scanf("%i %i",&n,&i);
	i*=8;
	int num=i/n;
	int number=1;
	for(int i=0;i<num;i++)
        if(number<n)
            number*=2;
	map<int,int> cnt;
	for(int i=0;i<n;i++)
        scanf("%i",&a),cnt[a]++;
    vector<int> values;
    for(auto p:cnt)
        values.pb(p.s);
    int m=values.size();
    vector<int> suff(3*m);
    suff[m-1]=values[m-1];
    for(int i=m-2;i>=0;i--)
        suff[i]=values[i]+suff[i+1];
    if(values.size()<=number)
    {
        printf("0\n");
        return 0;
    }
    int sum=0,treba=max((int)m-number,0),sol=INT_MAX;
    for(int i=0;i<m;i++)
    {
        sol=min(sol,sum+suff[m-treba+i]);
        sum+=values[i];
    }
    printf("%i\n",sol);
    return 0;
}