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
#define fl; fflush(stdout);

bool cmp2(pair<int,int> a,pair<int,int> b){
    printf("? %i %i\n",a.f+1,b.f+1);
    fl;
    char c;
    cin >> c;
    return c=='<';
}
bool cmp(int a,int b){
    printf("? %i %i\n",a+1,b+1);
    fl;
    char c;
    cin >> c;
    return c=='<';
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> > p;
        for(int i=0;i<n;i++){
            pair<int,int> tr={2*i,2*i+1};
            printf("? %i %i\n",tr.f+1,tr.s+1);
            fl;
            char c;
            cin >> c;
            if(c=='>')
                swap(tr.f,tr.s);
            p.pb(tr);
        }
        sort(all(p),cmp2);
        vector<int> dole,gore;
        for(int i=0;i<n;i++)
            dole.pb(p[i].f);
        for(int i=0;i<n-1;i++)
            gore.pb(p[i].s);
        sort(all(gore),cmp);
        reverse(all(gore));
        while(dole.size()){
            printf("? %i %i\n",gore.back()+1,dole.back()+1);
            fl;
            char c;
            cin >> c;
            if(c=='<')
                dole.pop_back(),gore.pop_back();
            else
                break;
        }
        printf("!\n");
        fl;
    }
    return 0;
}