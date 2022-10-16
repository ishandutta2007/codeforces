#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define double long double
#define MAX 600100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353 ;

ll dg[20][20]; // sum of jth digits of an i digit number
ll num[20];    // number of i digit numbers
ll pv[30];
void disp(deque<char>& a){
	for(auto f : a)
		cout<<f;
	cout<<endl;
}
deque<char> f(deque<char> a, deque<char> b){
	deque<char> ans;
//	cout<<"we combinin: \n";
//	disp(a);
//	disp(b);
	while(a.size() && b.size())
		ans.push_front(*(b.end()-1)), ans.push_front(*(a.end()-1)), b.pop_back(), a.pop_back();
	while(a.size() || b.size()){
		if(b.size())
			ans.push_front(*(b.end()-1)), b.pop_back();
		else
			ans.push_front(*(a.end()-1)), a.pop_back();
	}
//	cout<<"and we got \n";
//	disp(ans);
	return ans;
}
void pre(){
	pv[0] = 1;
	for(ll i = 1; i<30; i++)
		pv[i] = pv[i-1]*10, pv[i]%=modulo;
}
void deal(){
	pre();
	ll n;
	cin>>n;
	fori(n){
		ll ed;
		cin>>ed;
		vector<ll> dig;
		while(ed){
			dig.pb(ed%10);
			ed/=10;
		}
		reverse(dig.begin(), dig.end());
		forj(dig.size())
			dg[dig.size()][j]+=dig[j];
		num[dig.size()]++;
	}
	ll sum = 0;
	for(ll i = 1; i<11; i++)
		for(ll j = 1; j<11; j++){
			if(!num[i] || !num[j])
				continue;
			// combine i digit num with j digit num
			deque<char> a, b, answer;
			fork(i)
				a.pb((char)('a'+k));
			fork(j)
				b.pb((char)('A'+k));
			
			answer = f(a,b);
			fork(answer.size()){
				if(answer[k] >= 'a' && answer[k] <= 'z'){
					ll dif = (answer.size()-1-k);
					sum+=pv[dif] * dg[i][answer[k]-'a'] % modulo * num[j] % modulo;
					sum %= modulo;
				}
			}
			
			answer = f(b,a);
			
			fork(answer.size()){
				if(answer[k] >= 'a' && answer[k] <= 'z'){
					ll dif = (answer.size()-1-k);
					sum+=pv[dif] * dg[i][answer[k]-'a'] % modulo * num[j] % modulo;
					sum %= modulo;
				}
			}
		}
	cout<<sum;
}
int main(){
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}