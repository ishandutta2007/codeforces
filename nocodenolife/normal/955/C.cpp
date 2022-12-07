#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int primes[17] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
	vector <ll > stored;
	int p;
	ll powed;
	map <ll,ll> checker;
	for(int h=1;h<17;h++)
	{
	    p = primes[h];
	    double pow1 = 18.0/p;
	    ll togo = pow(10,pow1);
	    for(ll k=2;k<=togo+1;k++)
	    {
	        powed = (ll)sqrt(k);
	        if(powed*powed==k || (powed+1)*(powed+1)==k)
	            continue;
	        ll val = pow(k,p);
	        if(val<1e18 && val>0)
	        {
	            if(checker[val]==0)
	                stored.push_back(val);
	            checker[val]++;
	        }
	    }
	}
	sort(stored.begin(), stored.end());
	ll q,l,r,answer;
	cin>>q;
	for(ll i=0;i<q;i++)
	{
	    cin>>l>>r;
	    answer = 0;
	    l--;
	    answer += (ll)(upper_bound(stored.begin(), stored.end(), r) - stored.begin());
	    answer -= (ll)(upper_bound(stored.begin(), stored.end(), l) - stored.begin());
	    //cout<<answer<<endl;
	    powed = (ll) sqrt(r);
	    if((powed+1)*(powed+1) <= r)
	        powed++;
	    answer+=powed;
	    powed = (ll) sqrt(l);
	    if((powed+1)*(powed+1) <= l)
	        powed++;
	    answer-=powed;
	    
	    cout<<answer<<endl;//<<endl;
	}
    return 0;
}