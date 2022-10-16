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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
    srand(time(NULL));
    int lim=4e4;
    int cnt=0;
    vector<int> ra;
    for(int i=0;i<lim;i++)
        ra.pb(rand());
    /*for(int i=0;i<lim;i++)
    {
        if(rand()%10==0)
            ra[i]=0;
    }*/
    for(int k=0;k<lim;k++)
    {
        for(int i=0;i<lim;i++)
        {
            for(int j=ra[i];j;j=(j-1)%ra[i])
            {
                cnt++;
            }
            if(i>0)
                ra[i-1]=ra[i];
        }
    }
	int n;
	scanf("%i",&n);
	string s;
	cin >> s;
	int tr=0;
	int nxt=1;
	string sol;
	while(tr<n)
    {
        sol+=s[tr];
        tr+=nxt;
        nxt++;
    }
    cout << sol;
    return 0;
}