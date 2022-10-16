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
	int n,sx,sy;
	scanf("%i %i %i",&n,&sx,&sy);
	int mx=0,vx=0,my=0,vy=0;
	for(int i=0;i<n;i++){
        int x,y;
        scanf("%i %i",&x,&y);
        if(x<sx)
            mx++;
        if(x>sx)
            vx++;
        if(y<sy)
            my++;
        if(y>sy)
            vy++;
	}
	int m=max({mx,vx,my,vy});
	if(m==mx){
        printf("%i\n%i %i\n",m,sx-1,sy);
        return 0;
	}
	if(m==vx){
        printf("%i\n%i %i\n",m,sx+1,sy);
        return 0;
	}
	if(m==my){
        printf("%i\n%i %i\n",m,sx,sy-1);
        return 0;
	}
	if(m==vy){
        printf("%i\n%i %i\n",m,sx,sy+1);
        return 0;
	}
    return 0;
}