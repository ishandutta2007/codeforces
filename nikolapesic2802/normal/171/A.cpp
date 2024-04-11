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
    string a,b;
    cin >> a >> b;
    int koliko=max(a.size(),b.size());
    a="000000000"+a;
    b+="000000000";
    ll ans=0;
    for(int i=koliko-1;i>=0;i--)
    {
        ans=ans*10+a[a.size()-1-i]-'0'+b[i]-'0';
    }
    printf("%lld\n",ans);
	/*int n;
	scanf("%i",&n);
	vector<int> sol(n),arr(n);
	for(int i=0;i<n;i++){
        scanf("%i",&arr[i]);
	}
    vector<pair<int,int> > des,asc;
    for(int i=0;i<n;i++)
    {
        while(asc.size()>0&&asc.back().f>=arr[i])
        {
            if((des.size()==0||des.back().f>asc.back().f)&&(asc.size()==1||asc[asc.size()-2].f<arr[i]))
            {
                des.pb(asc.back());
                asc.pop_back();
            }
            else
                break;
        }
        if(asc.size()&&asc.back().f>=arr[i])
        {
            des.pb({arr[i],i});
        }
        else
        {
            asc.pb({arr[i],i});
        }
    }
    for(int i=1;i<des.size();i++)
        if(des[i].f>=des[i-1].f)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    for(auto p:des)
        sol[p.s]=1;
    for(int i=0;i<n;i++)
        printf("%i ",sol[i]);
    return 0;*/
}