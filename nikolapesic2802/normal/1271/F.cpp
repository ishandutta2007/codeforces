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

vector<pair<int,int> > bounds(3);
vector<int> d(7);
vector<int> dva={1,2,4};
vector<int> ans(7);
bool gen(int tr,int a,int b,int c){
    if(a>bounds[0].s||b>bounds[1].s||c>bounds[2].s)
        return 0;
    if(tr==0){
        for(int i=0;i<=d[4];i++){
            ans[4]=i;
            if(gen(tr+1,a+i,b+i,c))
                return 1;
        }
        return 0;
    }
    if(tr==1){
        for(int i=0;i<=d[2];i++){
            ans[2]=i;
            if(gen(tr+1,a+i,b,c+i))
                return 1;
        }
        return 0;
    }
    if(tr==2){
        for(int i=0;i<=d[1];i++){
            ans[1]=i;
            if(gen(tr+1,a,b+i,c+i))
                return 1;
        }
        return 0;
    }
    if(a>bounds[0].s||b>bounds[1].s||c>bounds[2].s)
        return 0;
    //printf("%i %i %i %i\n",tr,a,b,c);
    int diff=min({bounds[0].s-a,bounds[1].s-b,bounds[2].s-c});
    ans[0]=min(d[0],diff);
    a+=ans[0];
    b+=ans[0];
    c+=ans[0];
    if(bounds[0].f-a<=d[6]&&bounds[1].f-b<=d[5]&&bounds[2].f-c<=d[3]){
        ans[6]=max(0,bounds[0].f-a);
        ans[5]=max(0,bounds[1].f-b);
        ans[3]=max(0,bounds[2].f-c);
        for(int i=0;i<7;i++)
            printf("%i ",ans[i]);
        printf("\n");
        return 1;
    }
    return 0;
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--){
        vector<pair<int,int> > a(3);
        scanf("%i %i %i %i %i %i",&a[2].f,&a[1].f,&a[0].f,&a[2].s,&a[1].s,&a[0].s);
        for(int i=0;i<7;i++)
            scanf("%i",&d[i]);
        vector<int> cnt(3);
        for(int i=0;i<7;i++){
            for(int j=0;j<3;j++){
                if((i&(1<<j))==0){
                    cnt[j]+=d[i];
                }
            }
        }
        bool no=0;
        for(int i=0;i<3;i++){
            if(a[i].f+a[i].s<cnt[i]){
                printf("-1\n");
                no=1;
                break;
            }
            int prostora=a[i].f+a[i].s-cnt[i];
            bounds[i].f=max(0,a[i].f-prostora);
            bounds[i].s=a[i].f;
        }
        //cout << bounds << endl;
        if(no)
            continue;
        if(!gen(0,0,0,0))
            printf("-1\n");
	}
    return 0;
}