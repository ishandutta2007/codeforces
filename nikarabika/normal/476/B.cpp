#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

float C(int n, int r){
	if(r==0)
		return 1;
	else if(r>n)
		return 0;
	int ans=1;
	FOR(i, r+1, n){
		ans*=i;
		ans/=i-r;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	string s, t;
	cin>>s>>t;
	int ss=0;
	int ts=0, soal=0;
	rep(i, s.size())
		if(s[i]=='+')
			ss++;
		else
			ss--;
	rep(i, t.size())
		if(t[i]=='+')
			ts++;
		else if(t[i]=='-')
			ts--;
		else
			soal++;
	int d=abs(ts-ss);
	int r=(soal-d)/2;
	cout.precision(12);
	cout.setf(ios::fixed, ios::floatfield);
	if(soal==0 && d!=0)
		cout<<"0.000000000000"<<endl;
	else if(r*2!=soal-d)
		cout<<"0.000000000000"<<endl;
	else
	cout<<C(soal, r)/(1<<soal)<<endl;
	return 0;
}