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

const int N=2750132;
int visited[N],skip[N],cnt[N];
void fastscan(int &number)
{
    char c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
void write(int i)
{
    if(i>9)
        write(i/10);
    putchar(i%10+48);
}
int main()
{
    int tr=1;
    vector<int> primes;
    for(int i=2;i<N;i++)
    {
        if(visited[i]==0){
            visited[i]=tr++;
            primes.pb(i);
        }
        for(auto p:primes)
        {
            if(p*i>=N)
                break;
            visited[p*i]=-i;
            if(i%p==0)
                break;
        }
    }
    int n,a;
    fastscan(n);
	vector<int> arr;
	for(int i=0;i<2*n;i++)
        fastscan(a),cnt[a]++;
    for(int i=N-1;i>=0;i--)
        while(cnt[i]--)
        {
            if(skip[i])
            {
                skip[i]--;
            }
            else
            {
                if(visited[i]<0)
                {
                    write(i);
                    putchar(' ');
                    skip[-visited[i]]++;
                }
                else
                {
                    write(visited[i]);
                    putchar(' ');
                    skip[visited[i]]++;
                }
            }
        }
    return 0;
}