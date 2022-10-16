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
    int n,h;
    scanf("%i %i",&n,&h);
    vector<int> a(n);
    int mn=INT_MAX,gde=0;
    for(int i=0;i<n;i++){
        scanf("%i",&a[i]);
        if(mn>a[i])
            mn=a[i],gde=i;
    }
    sort(all(a));
    int o1=(a[n-1]+a[n-2])-(a[0]+a[1]);
    if(n==2){
        printf("0\n1 1\n");
        return 0;
    }
    int o2=max({(a[n-1]+a[n-2])-(a[1]+a[2]),abs(a[n-1]+a[n-2]-(a[0]+a[1]+h)),abs(a[1]+a[2]-(a[0]+a[n-1]+h))});
    if(o1<=o2){
        printf("%i\n",o1);
        for(int i=0;i<n;i++)
            printf("1 ");
        return 0;
    }
    printf("%i\n",o2);
    for(int i=0;i<n;i++)
        if(i==gde)
            printf("1 ");
        else
            printf("2 ");
    return 0;
}