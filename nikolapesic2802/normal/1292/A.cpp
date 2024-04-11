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
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

vector<int> dx={1,-1,0,0,1,1,-1,-1},dy={0,0,1,-1,1,-1,1,-1};
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,q;
	scanf("%i %i",&n,&q);
	vector<vector<int> > state(2,vector<int>(n));
	set<pair<pair<int,int>,pair<int,int> > > blocks;
	for(int i=0;i<q;i++){
        int x,y;
        scanf("%i %i",&x,&y);
        x--;y--;
        if(state[x][y]){
            for(int k=0;k<8;k++){
                int xx=x+dx[k],yy=y+dy[k];
                if(xx<2&&xx>=0&&yy<n&&yy>=0&&xx!=x&&state[xx][yy]){
                    blocks.erase({{xx,yy},{x,y}});
                    blocks.erase({{x,y},{xx,yy}});
                }
            }
        }
        else{
            for(int k=0;k<8;k++){
                int xx=x+dx[k],yy=y+dy[k];
                if(xx<2&&xx>=0&&yy<n&&yy>=0&&xx!=x&&state[xx][yy]){
                    blocks.insert({{xx,yy},{x,y}});
                    blocks.insert({{x,y},{xx,yy}});
                }
            }
        }
        state[x][y]^=1;
        printf(blocks.size()?"No\n":"Yes\n");
	}
    return 0;
}