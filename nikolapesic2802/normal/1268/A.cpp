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
	int n,k;
	scanf("%i %i",&n,&k);
	string s;
	cin >> s;
	bool good=true;
	for(int i=0;i<n-k;i++)
        if(s[i]!=s[i+k])
            good=false;
    if(good){
        cout << n << endl;
        cout << s << endl;
        return 0;
    }
    string aaa=s;
    bool uspelo=true;
    bool povecao=false;
    for(int i=0;i<n-k;i++){
        if(aaa[i]>aaa[i+k]){
            aaa[i+k]=aaa[i];
            povecao=true;
        }
        if(aaa[i]<aaa[i+k]){
            if(!povecao)
                uspelo=false;
            aaa[i+k]=aaa[i];
        }
    }
    if(uspelo){
        cout << n << endl << aaa << endl;
        return 0;
    }
    s='0'+s;
    s[k]++;
    for(int i=k;i>=0;i--){
        if(s[i]==('9'+1))
            s[i]='0',s[i-1]++;
    }
    if(s[0]=='0')
        s=s.substr(1,n);
    for(int i=0;i<(int)s.size()-k;i++)
        s[i+k]=s[i];
    printf("%i\n",s.size());
    cout << s << endl;
    return 0;
}