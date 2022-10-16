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
	int m;
	scanf("%i",&m);
	int h1,a1,x1,y1,h2,a2,x2,y2;
	scanf("%i %i %i %i %i %i %i %i",&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
	vector<int> visited1(m),visited2(m);
	visited1[h1]=1;visited2[h2]=1;
	int t1=-1,c1,d1=-1,t2=-1,c2,d2=-1;
	ll tr=2;
	vector<int> n1,n2;
	n1.pb(h1);
	n2.pb(h2);
	for(int k=0;k<2*m;k++)
    {
        h1=((ll)h1*x1+y1)%m;
        h2=((ll)h2*x2+y2)%m;
        if(t1==-1)
            n1.pb(h1);
        if(t2==-1)
            n2.pb(h2);
        if(visited1[h1]&&t1==-1)
            t1=visited1[h1],c1=tr-t1;
        if(visited2[h2]&&t2==-1)
            t2=visited2[h2],c2=tr-t2;
        visited1[h1]=tr;
        visited2[h2]=tr;

        if(h1==a1&&h2==a2)
        {
            printf("%lld\n",tr-1);
            return 0;
        }
        if(h1==a1)
        {
            if(t1!=-1){
                swap(h1,h2);
                swap(a1,a2);
                swap(x1,x2);
                swap(y1,y2);
                swap(t1,t2);
                swap(c1,c2);
                swap(d1,d2);
                swap(n1,n2);
                swap(visited1,visited2);
            }
        }
        if(h2==a2)
        {
            if(t2!=-1)
            {
                if(t1!=-1)
                {
                    for(int j=0;j<m;j++)
                    {
                        h1=n1[(visited1[h1]+c2-t1)%c1+t1-1];
                        tr+=c2;
                        if(h1==a1)
                        {
                            printf("%lld\n",tr-1);
                            return 0;
                        }
                    }
                    printf("-1\n");
                    return 0;
                }
            }
        }
        tr++;
    }
    printf("-1\n");
    return 0;
}