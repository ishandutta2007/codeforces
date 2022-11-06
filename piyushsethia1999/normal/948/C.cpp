#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF (1<<30)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	ll T[n],V[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>V[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>T[i];
	}
	priority_queue <ll, vector<ll>, greater<ll> > pq;
    ll t=0,t1;
    ll Tr;
    ll l=0;
    for (int i = 0; i < n; ++i)
    {
    	Tr=0;
    	t1=t;
    	pq.push(V[i]+t);
    	l++;
    	t+=T[i];
    	while((!pq.empty())&&(pq.top()<t)){
    		Tr+=(pq.top()-t1);
    		pq.pop();
    		l--;
    	}
    	Tr+=(l*T[i]);
    	cout<<Tr<<" ";
    }
}