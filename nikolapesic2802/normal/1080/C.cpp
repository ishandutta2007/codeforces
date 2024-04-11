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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
bool getcolor(int x,int y)
{
    if((x+y)%2==0)
        return false;
    return true;
}
void test()
{
    int n,m;
    scanf("%i %i",&n,&m);
    swap(n,m);
    int x1,y1,x2,y2;
    scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
    int x3,y3,x4,y4;
    scanf("%i %i %i %i",&x3,&y3,&x4,&y4);
    ll black=((ll)n*m)/2;
    ll white=(ll)n*m-black;
   // printf("%lld %lld\n",white,black);
    int x5=max(x1,x3),y5=max(y1,y3),x6=min(x2,x4),y6=min(y2,y4);
    ll b=(ll)(x2-x1+1)*(y2-y1+1)/2;
    if(getcolor(x1,y1)&&getcolor(x2,y2)&&(ll)(x2-x1+1)*(y2-y1+1)%2==1)
        b++;
    white+=b;
    black-=b;
    //printf("%lld %lld\n",white,black);
    ll w=(ll)(x4-x3+1)*(y4-y3+1)/2;
    if(!getcolor(x3,y3)&&!getcolor(x4,y4)&&(ll)(x4-x3+1)*(y4-y3+1)%2==1)
        w++;
    black+=w;
    white-=w;
    //printf("%lld %lld\n",white,black);
    if(x6>=x5&&y6>=y5){
    ll b=(ll)(x6-x5+1)*(y6-y5+1)/2;
    if(getcolor(x5,y5)&&getcolor(x6,y6)&&(ll)(x6-x5+1)*(y6-y5+1)%2==1)
        b++;
    white-=b;
    black+=b;
    //printf("%lld %lld\n",white,black);
    }
    printf("%lld %lld\n",white,black);
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
        test();
    return 0;
}