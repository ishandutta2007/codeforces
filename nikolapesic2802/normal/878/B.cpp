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

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
	int n,k,m;
	scanf("%i %i %i",&n,&k,&m);
	vector<int> a(n);
	deque<pair<int,int> > arr;
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=0;i<n;i++)
        if(arr.size()&&a[i]==arr.back().f){
            arr.back().s++;
            if(arr.back().s==k)
                arr.pop_back();
        }
        else
            arr.pb({a[i],1});
    for(auto &p:arr)
        p.s%=k;
    deque<pair<int,int> > start=arr;
    int siz=0;
    for(auto p:arr)
        siz+=p.s;
    if(m==1)
    {
        printf("%i\n",siz);
        return 0;
    }
    if(arr.size()==1)
    {
        printf("%i\n",(ll)n*m%k);
        return 0;
    }
    int sklonio=0;
    deque<pair<int,int> > ss=arr;
    while(arr.size()&&ss.size())
    {
        if(arr.back().f!=ss.front().f)
            break;
        int su=arr.back().s+ss.front().s;
        int mm=su%k;
        sklonio+=su-mm;
        if(mm!=0)
        {
            if(arr.size()==1)
            {
                int ostalo=2*siz-sklonio;
                if(m%2==0)
                {
                    printf("%i\n",((ll)ostalo*m/2)%k);
                    return 0;
                }
                else
                {
                    ll kolicina=(ll)ostalo*m/2+start[0].s;
                    printf("%i\n",kolicina%k+siz-start[0].s);
                    return 0;
                }
            }
            else
            {
                if(sklonio<siz)
                    break;
                assert(arr.back().s==ss.front().s);
                int ostalo=(ll)arr.back().s*m%k;
                if(ostalo==0)
                {
                    printf("0\n");
                    return 0;
                }
                if(ostalo!=0)
                {
                    printf("%i\n",2*siz-sklonio+su-mm-arr.back().s*2+ostalo);
                    return 0;
                }
            }
        }
        arr.pop_back(),ss.pop_front();
    }
    if(sklonio>siz)
    {
        if(m%2)
            printf("%i\n",siz);
        else
            printf("0\n");
        return 0;
    }
    printf("%lld\n",(ll)siz*m-(ll)sklonio*(m-1));
    return 0;
}