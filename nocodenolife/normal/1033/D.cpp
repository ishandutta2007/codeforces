#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 998244353
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<ll,ll> mapper;
    int n;
    cin>>n;
    vector<ll> fours;
    ll num,sq,sqsq,thr;
    set<ll> prim;
    set<ll> prim2;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        cout.flush();

        sq = sqrt(num);
        if((sq+1)*(sq+1)==num)
        {
            sq++;
        }
        if(sq*sq==num)
        {
            sqsq = sqrt(sq);
            if((sqsq+1)*(sqsq+1)==sq)
                sqsq++;
            if(sqsq*sqsq == sq)
            {
                mapper[sqsq]+=4;
                prim.insert(sqsq);
            }
            else
            {
                mapper[sq]+=2;
                prim.insert(sq);
            }
            continue;
        }
        thr = cbrt(num);
        if((thr+1)*(thr+1)*(thr+1)==num)
        {
            thr++;
        }
        if(thr*thr*thr==num)
        {
            mapper[thr]+=3;
            prim.insert(thr);
            continue;
        }
        fours.push_back(num);
    }
    ll si = fours.size();
    ll store;
    
    for(ll i=0;i<si;i++)
    {
        for(ll j=i+1;j<si;j++)
        {
            store = __gcd(fours[i],fours[j]);
            if(store!=1 && fours[i]!=fours[j])
            {
                prim.insert(store);
            }
            else if(store!=1)
            {
                prim2.insert(store);
            }
        }
    }
    set <ll> :: iterator itr;
    for(itr = prim.begin(); itr!=prim.end();itr++)
    {
        for(ll j=0;j<si;j++)
        {
            if(fours[j]%(*itr)==0)
            {
                mapper[*itr]++;
                mapper[(fours[j]/(*itr))]++;
                fours[j] = 1;
            }
        }
    }

    map<ll,ll> mapper2;
    for(itr = prim2.begin(); itr!=prim2.end();itr++)
    {
        for(ll j=0;j<si;j++)
        {
            if(fours[j]==(*itr))
            {
                mapper2[*itr]++;
                fours[j] = 1;
            }
        }
    }

    ll answer = 1;
    for(ll j=0;j<si;j++)
    {
        if(fours[j]!=1)
        {
            answer*=4;
            answer%=mod;
        }
    }

    map <ll, ll> :: iterator it;

    for(it = mapper.begin();it!=mapper.end();it++)
    {
        // cout<<it->first<<" "<<it->second<<endl;
        answer*= (it->second+1);
        answer%=mod;
    }

    for(it = mapper2.begin();it!=mapper2.end();it++)
    {
        // cout<<it->first<<" "<<it->second<<endl;
        answer*= (it->second+1);
        answer%=mod;
        answer*= (it->second+1);
        answer%=mod;
    }

    cout<<answer<<endl;
    cout.flush();
    return 0;
}