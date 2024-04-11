#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
std::vector<ll> step2yinc;
std::vector<ll> step3yinc;
std::vector<ll> v;
bool visitedforstep3[200001];
bool visitedforstep2[200001];
ll n;
ll calcstep2(ll i);
ll calcstep3(ll i);

ll calcstep3(ll i){
	if((!step3yinc[i]) && visitedforstep3[i]){
		step3yinc[i] = -1;
		return -1;
	}
	if(visitedforstep3[i])
	{
		return step3yinc[i];
	}
	visitedforstep3[i] = true;
	if((i - v[i]) == 1){
		step3yinc[i] = -1;
		return -1;
	}
	if((i - v[i]) <= 0)
	{
		step3yinc[i] = v[i];
		return v[i];
	}
	ll t = calcstep2(i - v[i]);
	if(t == -1)
	{
		step3yinc[i] = -1;
		return -1;
	}
	step3yinc[i] = t + v[i];
	return step3yinc[i];
}

ll calcstep2(ll i){
	if(visitedforstep2[i] && (!step2yinc[i])) {
		step2yinc[i] = -1;
		return -1;
	}
	if(visitedforstep2[i]){
		return step2yinc[i];
	}
	visitedforstep2[i] = true;
	if((i + v[i]) > n)
	{
		step2yinc[i] = v[i];
		return v[i];
	}
	ll t = calcstep3(i + v[i]);
	if(t == -1)
	{
		step2yinc[i] = -1;
		return -1;
	}
	step2yinc[i] = t + v[i];
	return step2yinc[i];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin>>n;
	v.resize(n+1);
	step3yinc.resize(n+1, 0);
	step2yinc.resize(n+1, 0);
	for (ll i = 2; i <= n; ++i)
	{
		cin>>v[i];
	}
	for (ll i = 2; i <= n; ++i)
	{
		if(!step2yinc[i])
			step2yinc[i] = calcstep2(i);
		if(!step3yinc[i])
			step3yinc[i] = calcstep3(i);
	}
	print(step2yinc);
	print(step3yinc);
	for (ll i = 1; i <= n-1; ++i)
	{
		if(step3yinc[i+1] == -1)
			cout<<-1;
		else
			cout<<(step3yinc[i+1]+i);
		cout<<"\n";
	}
}