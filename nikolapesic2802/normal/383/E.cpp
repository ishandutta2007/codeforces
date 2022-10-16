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

const int L=24,N=1<<L;
int get(char c)
{
    return (1<<(c-'a'));
}
char s[10000][3];
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> cnt(N),nxt(N),ans(N);
	for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        cnt[get(s[i][0])]++;
        cnt[get(s[i][1])]++;
        cnt[get(s[i][2])]++;
    }
	for(int i=0;i<L;i++)
    {
        for(int x=0;x<N;x++)
            if(x&(1<<i))
                nxt[x]=cnt[x]+cnt[x^(1<<i)];
            else
                nxt[x]=cnt[x];
        cnt=nxt;
    }
    for(int i=0;i<N;i++)
        ans[i]+=cnt[i],cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        cnt[get(s[i][0])|get(s[i][1])]++;
        cnt[get(s[i][0])|get(s[i][2])]++;
        cnt[get(s[i][1])|get(s[i][2])]++;
    }
    for(int i=0;i<L;i++)
    {
        for(int x=0;x<N;x++)
            if(x&(1<<i))
                nxt[x]=cnt[x]+cnt[x^(1<<i)];
            else
                nxt[x]=cnt[x];
        cnt=nxt;
    }
    for(int i=0;i<N;i++)
        ans[i]-=cnt[i],cnt[i]=0;
    for(int i=0;i<n;i++)
        cnt[get(s[i][0])|get(s[i][1])|get(s[i][2])]++;
    for(int i=0;i<L;i++)
    {
        for(int x=0;x<N;x++)
            if(x&(1<<i))
                nxt[x]=cnt[x]+cnt[x^(1<<i)];
            else
                nxt[x]=cnt[x];
        cnt=nxt;
    }
    for(int i=0;i<N;i++)
        ans[i]+=cnt[i];
    int sol=0;
    for(int i=0;i<N;i++)
        sol^=(ans[i])*(ans[i]);
    printf("%i\n",sol);
    return 0;
}