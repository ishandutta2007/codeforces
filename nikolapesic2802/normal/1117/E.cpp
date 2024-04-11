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

string ask(string s)
{
    cout << "? " << s << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return ans;
}
const int N=1e4;
vector<int> sol(N);
vector<string> q;
void solve(int l,int r,int nivo,vector<int> pozicije)
{
    int n=(r-l+1);
    int pos=l;
    for(int k=0;k<26;k++)
    {
        vector<int> novo;
        for(auto p:pozicije)
            if(q[nivo][p]=='a'+k)
                novo.pb(p);
        if(novo.size()==1)
            sol[pos]=novo.front();
        if(novo.size()>1)
            solve(pos,pos+novo.size()-1,nivo+1,novo);
        pos+=novo.size();
    }
}
int main()
{
	string s;
	cin >> s;
	int n=s.size();
	string add(n,'a');
	int tr=26*26;
	for(int j=0;j<3;j++)
	{
        for(int i=0;i<n;i++)
            add[i]='a'+((i/tr)%26);
        q.pb(ask(add));
        tr/=26;
	}
    vector<int> pozicije;
    for(int i=0;i<n;i++)
        pozicije.pb(i);
    solve(0,n-1,0,pozicije);
    string sss;
    for(int i=0;i<n;i++)
        sss+=s[sol[i]];
    cout << "! " << sss << endl;
    return 0;
}