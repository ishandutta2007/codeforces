#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 
 
string converter(ll n){  
	string s="";
	ll i;    
	for(i=0; n>0; i++){    
		s += char(n%2 + int('0'));    
		n= n/2;  
	}    
	reverse(s.begin(), s.end());
	return s;
}
pair<long double,long double> solver(double x,double y,double x2, double y2){
	//m*x+n = y
	//m*x2+n = y2
	pair <long double,long double> ans;
	//cout << x << ' ' << y << ' '<<x2 << ' ' << y2 << endl;
	if (x == x2){
		
		ans.first = 0;
		ans.second = 0;
		return ans;
	}
	if (x2-x != 0){
		ans.first = (y2-y)/(x2-x);
	}
	else{
		ans.first = 0;
	}
	ans.second = y-ans.first*x;
	return ans;
}
const int N=1e5;
ll a[N][3],b[N][3];
 
void msort(int l, int r){
	int m=(l+r)/2;
	if (l == r-1){
		return;
	}
	msort(l,m);
	msort(m,r);
	int p1 = l;
	int p2 = m;
	int k = l; 
	while (k < r){
		if (p2 >= r || (p1 < m && (a[p1][0]<a[p2][0] || (a[p1][0] == a[p2][0] && a[p1][1] < a[p2][1])))){
			b[k][0] = a[p1][0];
			b[k][1] = a[p1][1];
			b[k][2] = a[p1][2];
			p1++;
		}
		else{
			b[k][0] = a[p2][0];
			b[k][1] = a[p2][1];
			b[k][2] = a[p2][2];
			p2++;
		}
		k++;
	}
	for (int i=l; i<r; i++){
		a[i][0] = b[i][0];
		a[i][1] = b[i][1];
		a[i][2] = b[i][2];
	}
}
vector <ll> ve;
int main(){
	ll n;
	cin >> n;
	rep (i,0,n){
		cin >> a[i][0] >> a[i][1];
		a[i][2] = i;
	}
	if (n == 3){
		cout << 1 <<' '<< 2 <<' '<< 3;
		return 0;
	}
	msort(0,n);
	//cout << a[4][0] <<' '<< a[4][1] << "ij" << endl;
	pair <long double,long double> p1,p2,p3;
	p1 = solver(a[0][0],a[0][1],a[1][0],a[1][1]);
	rep (i,2,n){
		p2 = solver(a[0][0],a[0][1],a[i][0],a[i][1]);
		p3 = solver(a[1][0],a[1][1],a[i][0],a[i][1]);
		if (i==4){
	//		cout << p1.first <<' ' << p1.second << endl;
	//		cout << p2.first <<' ' << p2.second << endl;
	//		cout << p3.first <<' ' << p3.second << endl;
		}
		if (p1!=p2 || p3!=p1 || p2 != p3){
			cout << a[0][2]+1 <<' '<< a[1][2]+1 <<' '<< a[i][2]+1;
			return 0;
		}
	}
}