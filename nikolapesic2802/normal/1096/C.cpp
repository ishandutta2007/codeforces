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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
vector<int> ans={0,180,90,60,45,36,30,180,45,20,18,180,15,180,90,12,45,180,10,180,9,60,90,180,15,36,90,20,45,180,6,180,45,60,90,36,5,180,90,60,9,180,30,180,45,4,90,180,15,180,18,60,45,180,10,36,45,60,90,180,3,180,90,20,45,36,30,180,45,60,18,180,5,180,90,12,45,180,30,180,9,20,90,180,15,36,90,60,45,180,4,180,45,60,90,36,15,180,90,20,9,180,30,180,45,12,90,180,5,180,18,60,45,180,30,36,45,20,90,180,6,180,90,60,45,36,10,180,45,60,18,180,15,180,90,8,45,180,30,180,9,60,90,180,10,36,90,60,45,180,12,180,45,20,90,36,15,180,90,60,18,180,20,180,45,24,90,180,30,180,36,40,45,180,60,72,90,120,180,360};

int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
    {
        int a;
        cin >> a;
        printf("%i\n",ans[a]);
    }
    return 0;
    printf("{0");
    for(int ang=1;ang<180;ang++){
        for(int n=3;n<=998244353;n++){
            double angle = (double)(180)/n;
            int t=(double)ang/angle;
            if(t*angle==ang&&t<=n-2)
            {
                printf(",%i",n);
                break;
            }
        }
    }
    printf("}");
    return 0;
}