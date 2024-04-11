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
const int N=1000000;
vector<int> Z(N);
void getZ(string s)
{
    int n=s.size();
    int L=0,R=0;
    for(int i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n&&s[R]==s[R-L])
                R++;
            Z[i]=R-L;
            R--;
        }
        else
        {
            int k=i-L;
            if(Z[k]<R-i+1)
                Z[i]=Z[k];
            else
            {
                L=i;
                while(R<n&&s[R-L]==s[R])
                    R++;
                Z[i]=R-L;
                R--;
            }
        }
    }
}
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	vector<int> cnt(2);
	for(auto p:s1)
        cnt[p-'0']++;
    getZ(s2+'$'+s2);
    int start=0;
    for(int i=1;i<s2.size();i++)
    {
        if(Z[i+s2.size()+1]==s2.size()-i)
        {
            start=s2.size()-i;
            break;
        }
    }
    string sol;
    bool uspeo=true;
    for(auto p:s2)
    {
        if(cnt[p-'0'])
            sol+=p,cnt[p-'0']--;
        else
        {
            uspeo=false;
            break;
        }
    }
    while(uspeo)
    {
        for(int i=start;i<s2.size();i++)
        {
            if(cnt[s2[i]-'0'])
                sol+=s2[i],cnt[s2[i]-'0']--;
            else
            {
                uspeo=false;
                break;
            }
        }
    }
    while(cnt[0])
        sol+='0',cnt[0]--;
    while(cnt[1])
        sol+='1',cnt[1]--;
    cout << sol;
    return 0;
}