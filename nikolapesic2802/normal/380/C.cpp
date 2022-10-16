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

const int N=1e6+5,L=20;
vector<bool> br(N);
int sum[N],n;
pair<int,int> nxt[N][L];
int get(int l,int r)
{
    int s=sum[r];
    if(l)
        s-=sum[l-1];
    return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	n=s.size();
	for(int i=0;i<n;i++)
        br[i]=s[i]=='(',sum[i]=s[i]==')';
    for(int i=1;i<n;i++)
        sum[i]+=sum[i-1];
    for(int i=0;i<L;i++)
        nxt[n][i].f=nxt[n-1][i].f=n,nxt[n-1][i].s=1;
    for(int i=n-2;i>=0;i--)
    {
        if(br[i])
        {
            if(br[i+1])
                nxt[i][0].f=min(n,nxt[i+1][0].f+1);
            else
                nxt[i][0].f=i+2;
            if(br[nxt[i][0].f])
                nxt[i][0].s=nxt[nxt[i][0].f][0].s,nxt[i][0].f=nxt[nxt[i][0].f][0].f;
        }
        else
            if(br[i+1])
                nxt[i][0].f=i+1,nxt[i][0].s=1;
            else
                nxt[i][0].f=nxt[i+1][0].f,nxt[i][0].s=nxt[i+1][0].s+1;
        for(int j=1;j<L;j++){
            nxt[i][j].f=nxt[nxt[i][j-1].f][j-1].f;
            nxt[i][j].s=nxt[i][j-1].s+nxt[nxt[i][j-1].f][j-1].s;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        int tr=l,sum=0;
        for(int j=L-1;j>=0;j--)
            if(nxt[tr][j].f<=r)
                sum+=nxt[tr][j].s,tr=nxt[tr][j].f;
        if(br[tr])
        {
            int kol=get(tr,r);
            sum+=r-tr+1-2*kol;
        }
        else
            sum+=r-tr+1;
        cout << r-l+1-sum << endl;
    }
    return 0;
}