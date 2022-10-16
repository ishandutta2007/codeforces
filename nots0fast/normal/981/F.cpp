#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define forx(v) for(lli x=0; x<v; x++)
#define lli long long int
#define MAX 100100
#define ch 201
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-12;
ifstream in;
ofstream out;
void deal(){
	lli n,l;
	cin>>n>>l;
	lli men[3*n], wmn[n];
	fori(n)
		cin>>men[i], men[n+i] = men[i]-l, men[2*n+i] = men[i] + l;
	sort(men,men+3*n);
	fori(n)
		cin>>wmn[i];
	sort(wmn,wmn+n);
	lli closest[n];
	lli max_dist = 0;
	fori(n){
		lli a = 0, b = 3*n-1;
		while(a<b){
			lli c = (a+b)/2+1;
			if(men[c] <= wmn[i])
				a=c;
			else
				b=c-1;
		}
		if(men[a+1]-wmn[i] < wmn[i] - men[a])
			++a;
		closest[i] = a;
		max_dist = max(max_dist,(lli)fabs(men[a]-wmn[i]));
	}
	lli a = max_dist , b = pow(10,9);
	while(a<b){
		lli c = (a+b)/2;
		lli lr[n][2];
		fori(n){
			lli a1 = 0, b1 = closest[i];
			while(a1<b1){
				lli c1 = (a1+b1)/2;
				if(men[c1] >= wmn[i]-c)
					b1 = c1;
				else
					a1 = c1+1;
			}
			lr[i][0] = a1;
			a1 = closest[i], b1 = 3*n-1;
			while(a1<b1){
				lli c1 = (a1+b1)/2+1;
				if(men[c1] <= wmn[i]+c)
					a1=c1;
				else
					b1=c1-1;
			}
			lr[i][1] = a1;
		}
		lli a1 = lr[0][0], b1 = lr[0][1];
		if(!a1 && b1>n-1)
			b1 = n-1;
		while(a1<b1){
			lli c1 = (a1+b1)/2;
			lli last = c1;
			for(lli i=1; i<n; i++){
				if(lr[i][1] <= last)
					break;
				last = max(last+1,lr[i][0]);
			}
			if(last-c1>=n)
				a1=c1+1;
			else
				b1=c1;
		} 
		lli last = a1;
		bool ook = 1;
		for(lli i=1; i<n; i++){
			if(lr[i][1] <= last){
				ook = 0;
				break;
			}
			last = max(last+1,lr[i][0]);
		}
		if(last-a1>=n || !ook)
			a=c+1;
		else
			b=c;
	}
	cout<<a;
}
int main() {
    deal();
}