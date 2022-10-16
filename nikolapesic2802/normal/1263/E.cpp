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
const int N=1e6+1;
vector<int> l(4*N),mi(4*N),ma(4*N);
void prop(int i)
{
  mi[2*i]+=l[i];
  mi[2*i+1]+=l[i];
  ma[2*i]+=l[i];
  ma[2*i+1]+=l[i];
  l[2*i]+=l[i];
  l[2*i+1]+=l[i];
  l[i]=0;
}
void update(int i)
{
  ma[i]=max(ma[2*i],ma[2*i+1]);
  mi[i]=min(mi[2*i],mi[2*i+1]);
}
void add(int qs,int qe,int x,int le=0,int r=N-1,int i=1)
{
 /* if(i==1)
    printf("\n%i %i %i\n",qs,qe,x);*/
  if(qs>r||qe<le)
    return;
  if(qs<=le&&qe>=r)
  {
    l[i]+=x;
    mi[i]+=x;
    ma[i]+=x;
    return;
  }
  prop(i);
  int m=(le+r)/2;
  add(qs,qe,x,le,m,2*i);
  add(qs,qe,x,m+1,r,2*i+1);
  update(i);
}
vector<int> sta(N,2);
int cnt;
void pr()
{
  if(mi[1]>=0&&cnt==0)
  {
    cout << ma[1] << " ";
    return;
  }
  cout << "-1 ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i=0;
    for(auto p:s)
    {
        if(p=='R')
        {
            i++;
            pr();
            continue;
        }
        if(p=='L')
        {
            i=max(0,i-1);
            pr();
            continue;
        }
        int old=sta[i];
        if(p=='(')
            sta[i]=0;
        if(p==')')
            sta[i]=1;
        if(p>='a'&&p<='z')
            sta[i]=2;
        if(old==0){
            if(sta[i]==1)
                add(i,N-1,-2),cnt-=2;
            if(sta[i]==2)
                add(i,N-1,-1),cnt--;
        }else
        if(old==1){
            if(sta[i]==0)
                add(i,N-1,2),cnt+=2;
            if(sta[i]==2)
                add(i,N-1,1),cnt++;
        }else
        if(old==2){
            if(sta[i]==0)
                add(i,N-1,1),cnt++;
            if(sta[i]==1)
                add(i,N-1,-1),cnt--;
        }
        pr();
    }
}