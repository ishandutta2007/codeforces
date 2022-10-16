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
const int N=2e5+5;
vector<int> par(N);
int find(int tr){
  return tr==par[tr]?tr:par[tr]=find(par[tr]);
}
void merge(int a,int b){
  par[find(a)]=find(b);
}
int main()
{
  iota(all(par),0);
 // int t;
  //cin >> t;
 // while(t--){
    int n;
    cin >> n;
    vector<int> vals;
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      vector<int> ima(26);
      for(auto p:s)
        ima[p-'a']=1;
      int num=0;
      for(int j=0;j<26;j++)
        if(ima[j])
          num+=1<<j;
      vals.pb(num);
    }
    map<int,int> mapa;
    for(int i=0;i<n;i++)
      mapa[vals[i]]=i;
    for(int i=0;i<26;i++)
    {
      int last=-1;
      for(int j=0;j<n;j++){
        int p=vals[j];
        if(p&(1<<i))
        {
          if(last!=-1)
            merge(last,mapa[p]);
          last=mapa[p];
        }
      }
    }
     set<int> s;
     for(auto p:vals)
       s.insert(find(mapa[p]));
     cout << s.size();
 // }
}