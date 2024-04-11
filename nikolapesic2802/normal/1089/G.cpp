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
void test()
{
    int k;
    scanf("%i",&k);
    int cnt=0;
    vector<int> kada(50);
    for(int i=0;i<7;i++)
    {
        scanf("%i",&kada[i]);
        if(kada[i]==1)
            cnt++;
    }
    for(int i=7;i<50;i++)
        kada[i]=kada[i-7];
    int l=0;
    if(k>cnt)
    {
        l=(k/cnt-1)*7;
        //printf("Dodao %i obrtaja\n",k/cnt-1);
        k-=l/7*cnt;
        //printf("K:%i  %i\n",k,cnt);
    }
    int minn=20;
    for(int i=0;i<7;i++)
    {
        int j=i;
        int cnt2=0;
        while(cnt2<k)
        {
            cnt2+=kada[j]==1;
            j++;
        }
        minn=min(minn,j-i);
    }
    printf("%i\n",l+minn);
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
        test();
    return 0;
}