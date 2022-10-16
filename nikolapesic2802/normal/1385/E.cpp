#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
    
using namespace std;
using namespace __gnu_pbds;
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<int D, typename T> struct Vec : public vector<Vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>
Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}};template<typename T> struct Vec<1, T> : public vector<T> {
Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}
const int N=2e5+5;
vector<int> in(N);
vector<int> un[N];
vector<int> ne[N];
vector<bool> done(N);
vector<int> dobri(N);
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
    
    int t;
    fastscan(t);
    while(t--)
    {
        int n, m;
		fastscan(n);
		fastscan(m);
        

        for(int i = 1; i <= n; i++)
            in[i] = 0,ne[i].clear(),un[i].clear();

        vector<pair<int,int>> res;
       
        for(int i = 1; i <= n; i++)
          {
            
           done[i]=false;}
        for(int i = 0 ; i < m; i++)
        {
            int t,x,y;
			fastscan(t);
			fastscan(x);
			fastscan(y);
            if(t==0)
            {
                un[x].pb(y);
                un[y].pb(x);
                
            }
            else
            {
                res.pb({x , y});
                in[y]++;
                ne[x].pb(y);
            }            
        }
		int top=0;
        for(int i = 1; i <= n; i++)
        {
            if(in[i] == 0)
                dobri[top++]=i;
        }
        int br = 0;

        while(top)
        {
            br++;
			int tr=dobri[--top];

            if(in[tr] == 0)
            {
                for(int x : un[tr])
                {
                    if(done[x]== false)
                    {
               
                        res.pb({tr, x});
                    }
                }
                for(int x : ne[tr])
                {
                    in[x]--;
                    if(in[x] == 0)
						dobri[top++]=x;
                }
            }
            done[tr]=true;
        }

        if(br == n)
        {
			putchar('Y');
			putchar('E');
			putchar('S');
			putchar('\n');
            for(auto p : res){
				write(p.first);
				putchar(' ');
				write(p.second);
				putchar('\n');
			}
        }
        else
        {
            putchar('N');
			putchar('O');
			putchar('\n');
        }           
    }
    
    return 0;
}