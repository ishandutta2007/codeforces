#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	string s;
	cin>>s;
	ll j = 0;
	ll si = s.size();
	std::vector<ll> v;
	std::vector<ll> oddendposcount;
	std::vector<ll> evenendposcount;
	ll start;
	while(j < si){
		start = j;
		char ch = s[j];
		ll count = 0;
		while(j < si && ch == s[j]) {
			count++;
			j++;
		}
		v.pb(count);
		if(start&1) {
			oddendposcount.pb((count+1)/2);
			evenendposcount.pb((count)/2);
		}
		else {
			oddendposcount.pb(count/2);
			evenendposcount.pb((count+1)/2);
		}
	}
	std::vector<ll> presum1;
	std::vector<ll> presum2;
	presum1.pb(oddendposcount[0]);
	presum2.pb(evenendposcount[0]);
	if(v.size() >= 2){
		presum1.pb(oddendposcount[1]);
		presum2.pb(evenendposcount[1]);
	}
	for (ll i = 2; i < v.size(); ++i)
	{
		presum1.pb(oddendposcount[i] + presum1[i-2]);
		presum2.pb(evenendposcount[i] + presum2[i-2]);
	}
	ll totalodd = 0;
	ll totaleven = 0;
	totalodd = (oddendposcount[0]*(oddendposcount[0]+1))/2 + (evenendposcount[0]*(evenendposcount[0]+1))/2 ;
	totaleven = oddendposcount[0]*evenendposcount[0];
	if(v.size() >= 2){
		totalodd += (oddendposcount[1]*(oddendposcount[1]+1))/2 + (evenendposcount[1]*(evenendposcount[1]+1))/2 ;
		totaleven += oddendposcount[1]*evenendposcount[1];
	}
	for (ll i = 2; i < v.size(); ++i)
	{
		totalodd += ((oddendposcount[i]*(oddendposcount[i]+1))/2 + (evenendposcount[i]*(evenendposcount[i]+1))/2 + oddendposcount[i]*presum1[i-2] + evenendposcount[i]*presum2[i-2]);
		totaleven += (oddendposcount[i]*evenendposcount[i] + oddendposcount[i]*presum2[i-2] + evenendposcount[i]*presum1[i-2]);
	}
	cout<<totaleven<<" "<<totalodd<<"\n";
}