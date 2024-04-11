#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

int sol,n,aa,best=INT_MAX,gde;
vector<pair<int,int> > stk;
void dodaj(int a)
{
    int mxLevo=0;
    while(stk.size()&&stk.back().f<a)
        mxLevo=max(mxLevo+1,stk.back().s+1),stk.pop_back();
    sol=max(sol,(int)stk.size()+mxLevo+1);
    stk.pb({a,mxLevo});
}
int main()
{
	scanf("%i",&n);
	deque<int> a(n);
	vector<int> koliko(n+1),solL(n+1),solR(n+1);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),a[i]=n-a[i]+1,koliko[a[i]]=i;
    while(a[0]!=n)
        aa=a[0],a.pop_front(),a.pb(aa);
    a.pb(n);
    for(int i=1;i<n;i++)
        dodaj(a[i]),solL[i]=sol;
    sol=0;
    stk.clear();
    for(int i=n-1;i>0;i--)
        dodaj(a[i]),solR[i]=sol;
    for(int i=0;i<n;i++)
        if(1+max(solL[i],solR[i+1])<best)
            best=1+max(solL[i],solR[i+1]),gde=a[i+1];
    printf("%i %i\n",best,koliko[gde]);
    return 0;
}