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

const int L=20;
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        vector<int> sum(n);
        auto get=[&](int l,int r){
            if(l<0)
                return 1;
            if(l>r)
                return 0;
            int ss=sum[r];
            if(l)
                ss-=sum[l-1];
            return ss;
        };
        for(int i=0;i<n;i++)
        {
            sum[i]+=s[i]=='1';
            if(i)
                sum[i]+=sum[i-1];
        }
        int cnt=0;
        for(int i=1;i<L;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                if(s[j]=='0')
                    continue;
                int num=0;
                for(int k=j;k<j+i;k++)
                    num*=2,num+=s[k]=='1';
                int ostalo=num-i;
                if(ostalo>=0&&get(j-ostalo,j-1)==0)
                    cnt++;
            }
        }
        printf("%i\n",cnt);
    }
    return 0;
}