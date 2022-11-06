#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ul long long int
#define ll unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;

ll gcd(ll a, ll b) {
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
int main()
{
	fastio;
	#ifdef PIYUSH_AASHIRWAAD 
		I_O; 
	#endif	
	ll n, p, q, b, l;
	cin>>n;
	while(n--) {
		cin>>p>>q>>b;
		p = p%q;
		l = gcd(q, p);
		p /= l;
		q /= l;
		if(p == 0)
			cout<<"Finite\n";
		else {
			l = gcd(q, b);
			while((l != 1) && (q != 1 && q%l == 0)) {
				q = q/l;
				l = gcd(l, q);
			}
			if(q == 1) {
				cout<<"Finite\n";
			}
			else{
				cout<<"Infinite\n";
			}
		}
	}
}