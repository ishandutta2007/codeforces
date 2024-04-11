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
int n;
int ask(int poz)
{
    printf("? %i %i\n",poz,n);
    fflush(stdout);
    int a;
    scanf("%i",&a);
    return a;
}
int main()
{
	int t,next;
	scanf("%i %i",&n,&t);
	vector<int> niz(n+1);
	int pre=0;
	for(int poz=1;poz<n;poz++)
    {
        for(int i=0;i<15;i++)
        {
            ask(poz+1);
            next=ask(poz+1);
            if(next!=t)
                break;
        }
        int diff=next-t-poz+1+2*pre;
        if(diff==-1)
            niz[poz]=1,pre++;
        else
            niz[poz]=0;
        while(next!=t)
            ask(poz+1),next=ask(poz+1);
    }
    if(pre==t)
        niz[n]=0;
    else
        niz[n]=1;
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%i",niz[i]);
    return 0;
}